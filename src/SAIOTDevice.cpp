#include <Arduino.h>
#include "SAIOTDevice.h"

void SAIOTDevice::setDevice()[
	
	
	socket.on("eventoPadraoOn", dataVolta);
]

void SAIOTDevice::startWifi(){
	//Uncoment to always open mode AP
	//wifi.startConfigPortal();
	wifi.autoConnect();
	Serial.print(F("[SAIOT] connected to "));
	Serial.println(F(WiFi.SSID()));
}

void SAIOTDevice::startWSConnection(String host, String port){
	if (!socket.connect(host, port)) {
		Serial.println(F("[SAIOT] connection device-server failed"));
		return;
	} else if (socket.connected()) {
		Serial.println(F("[SAIOT] connection device-server established"));
	}
	Serial.flush();
}

void deviceHandle(){
	socket.emit("eventoPadrao", data);
}
