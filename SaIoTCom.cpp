#include "SaIoTCom.h"


SaIoTCom::SaIoTCom(){
};
SaIoTCom::SaIoTCom(WiFiClient& espClient){
  mqttClient.setClient(espClient);
};

boolean SaIoTCom::handleCom(void){
  return mqttClient.loop();
};

String SaIoTCom::getToken(String hostHttp, String user, String password, String serial){
  if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status
    String tokenRecebido;
    HTTPClient http;
    http.begin(hostHttp);  //Specify request destination
    http.addHeader("Content-Type","application/json");
    int httpCode = http.POST("{\"email\":\""+user+"\",\"password\":\""+password+"\",\"serial\":\"" + serial + "\"}");   //Send the request
    tokenRecebido += http.getString();
    Serial.println("Mensagem/token: " + tokenRecebido);
    http.end();
    return tokenRecebido;
 }else{
    Serial.println("ERROR GET TOKEN");
    //return pensar como seria o erro;
    return "";

  }
};

void SaIoTCom::setServerPort(const char* server, uint16_t port){
  mqttClient.setServer(server, port);
}

void SaIoTCom::setCallbackz(functionPointer f){
  mqttClient.setCallback(f);
}
void SaIoTCom::setClientw(WiFiClient& espClient){
  mqttClient.setClient(espClient);
}
void SaIoTCom::registerDevice(String serial,String user,String token,String jsonConf,const char* hostReg,String keys[], int nKeys){
  //#if usedProtocol == MQTT
      while (!mqttClient.connected()) {
      Serial.println("Tentando se conectar ao Broker MQTT" );
      if (mqttClient.connect(serial.c_str(),user.c_str(),token.c_str())) {
        Serial.println("Conectado!!");
        Serial.print("JSON CONFIG: ");
        Serial.println(jsonConf);
        Serial.println(mqttClient.subscribe(serial.c_str()));
        for(int i=0;i<nKeys;i++){
          Serial.println(mqttClient.subscribe((serial+keys[i]).c_str()));
        }
        //Serial.println(mqttClient.subscribe((serial+"ON").c_str())); 
        Serial.println(hostReg);
        Serial.println(mqttClient.publish(hostReg,jsonConf.c_str()));
      } else {
        Serial.println("Falha ao Reconectar");
        Serial.println("Tentando se reconectar em 2 segundos");
        delay(2000);
      }
    }
  //#endif
}

