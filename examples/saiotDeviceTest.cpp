/**
 * Exemplo de código de uma lâmpada controlada pela plataforma
 * SaIoT usando o protocolo MQTT. Nesse exemplo foi usado a
 * biblioteca para dispositivos IoT se comunicarem com a plata-
 * forma.
 * Autores:
 * Danielly Costa daniellycosta97@ufrn.edu.br
 * Patricio Oliveira patricio@bct.ect.ufrn.br
 * Ricardo Cavalcanti ricavalcanti@bct.ect.ufrn.br
 *
 * */

#include <Arduino.h>
#include <SaIoTDeviceLib.h>
#define timeToSend 30

WiFiClient espClient;
SaIoTDeviceLib lampadinha("DeviceTeste","115200zohn","ricardo@email.com");
SaIoTController onOff("on/off","simpleToogle","onoff");
SaIoTSensor medidorAgua("hd01","hidrometro_01","Litros","number");
String senha = "12345678910";
void callback(char* topic, byte* payload, unsigned int length);

unsigned long tDecorrido;
String getHoraAtual();
void setup(){
  lampadinha.addController(onOff);
  lampadinha.addSensor(medidorAgua);
  Serial.begin(115200);
  Serial.println("INICIO");
  lampadinha.preSetCom(espClient, callback);
  lampadinha.startDefault(senha);

	tDecorrido = millis();
  
}

void loop(){
	if( ((millis() - tDecorrido)/1000) >= timeToSend ){
		medidorAgua.sendData(random(1,30));
		tDecorrido = millis();
	}
	lampadinha.handleLoop();
}

void callback(char* topic, byte* payload, unsigned int length){
  String payloadS;
  Serial.print("Topic: ");
  Serial.println(topic);
  for (unsigned int i=0;i<length;i++) {
    payloadS += (char)payload[i];
  }
  if(strcmp(topic,lampadinha.getSerial().c_str()) == 0){
    Serial.println("SerialLog: " + payloadS);
  }
  if(strcmp(topic,(lampadinha.getSerial()+onOff.getKey()).c_str()) == 0){
    Serial.println("SerialLog: " + payloadS);
    //
  }
}
