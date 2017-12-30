#include "SAIOTDevice.h"

void SAIOTDevice::setDevice(deviceType device){
	if(device === accum){

	}else if (device === intens){

	}else if (device === intens){

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

	if (!socket.connect(host, port)) {
		Serial.println(F("[SAIOT] connection device-server failed"));
		return;
	} else if (socket.connected()) {
		Serial.println(F("[SAIOT] connection device-server established"));
	}
	Serial.flush();
}

void deviceHandle(){
	if (protocol === ws){
		client.monitor();
	}else if (protocol === mqtt){
		 client.loop();
	}/*else{ 
		implementar http
	}*/
}
