#include "SAIOTDevice.h"

void SAIOTDevice::setDevice(deviceType _device){
	if(_device == accum){
		AccumData device;

	}else if (_device == intens){
		IntensityDevice device;

	}else if (_device == instant){
		InstantData device;

	}else{
		Serial.print(F("[SAIOT] ERROR! invalid device type"));
	}
	
	//socket.on("eventoPadraoOn", dataVolta);
}

void SAIOTDevice::startWifi(){
	//Uncoment to always open mode AP
	//wifi.startConfigPortal();
	wifi.autoConnect();
	Serial.print(F("[SAIOT] connected to "));
	Serial.println(F(WiFi.SSID()));
}

void SAIOTDevice::startWSConnection(String host, String port){
	protocol = ws;

	if (!client.connect(host, port)) {
		Serial.println(F("[SAIOT] connection device-server failed"));
		return;
	} else if (client.connected()) {
		Serial.println(F("[SAIOT] connection device-server established"));
	}
	Serial.flush();
}

/*void SAIOTDevice::startMQTTConnection(String host, String port){
	protocol = mqtt;
	client.setServer(host, port);
	if (!client.connected()) {
		Serial.println(F("[SAIOT] connection device-server failed"));
		return;
  } else if (client.connected()){
	  Serial.println(F("[SAIOT] connection device-server established"));
  }
  Serial.flush();
  	//client.setCallback(callback);
}*/

void SAIOTDevice::deviceHandle(){
	if (protocol == ws){
		client.monitor();
	}else if (protocol == mqtt){
		 client.loop();
	}/*else{ 
		implementar http
	}*/
}

