#include"SaIoTDeviceLib.h"

void SaIoTDeviceLib::start(int boundRate){
	Serial.begin(boundRate);
  //Uncoment to always open mode AP
	//wifi.startConfigPortal();
	wifi.autoConnect();
	Serial.print(F("[SaIoT] connected to "));
 	Serial.println(WiFi.SSID());
}

void SaIoTDeviceLib::connect(String host, int port){
	switch(_protocol){
		case WS:

		if (!wsClient.connect(host, port)){
			Serial.println(F("[SaIoT] connection device-server failed"));
			return;
		}
		else if (wsClient.connected()){
			Serial.println(F("[SaIoT] connection device-server established"));
		}
		Serial.flush();
		break;

		case HTTP: Serial.println(F("[SaIoT] HTTP choosed - not setted"));
		case MQTT: Serial.println(F("[SaIoT] MQTT choosed - not setted"));
	}
}

void SaIoTDeviceLib::setName(String _name){
	name = _name;
}

String SaIoTDeviceLib::getName(void){
	return name;
}

void SaIoTDeviceLib::setSerial(String _serial){
	serial = _serial;
}

String SaIoTDeviceLib::getSerial(void){
	return serial;
}
    
void SaIoTDeviceLib::setIp(String _ip){
	ip = _ip;
}

String SaIoTDeviceLib::getIp(void){
	return ip;
}
    
void SaIoTDeviceLib::setProtocol(protocol protocolType){
	_protocol = protocolType;
}

protocol SaIoTDeviceLib::getProtocol(void){
	return _protocol;
}

void SaIoTDeviceLib::setSensors(String _sensor){
	sensor = _sensor;
}

String SaIoTDeviceLib::getSensors(void){
	return sensor;
}

void SaIoTDeviceLib::setControler(String _controler){

}

String SaIoTDeviceLib::getControler(void){

}

void SaIoTDeviceLib::handle(void){
	switch(_protocol){
		case WS:
			wsClient.monitor();
			break;
		case HTTP: Serial.println(F("[SaIoT] HTTP loop - not setted"));
		case MQTT: Serial.println(F("[SaIoT] MQTT loop - not setted"));
	}
}
/*void SaIoTDeviceLib::setUser(String user){
	_usuario = user;
}

String SaIoTDeviceLib::getUser(void){
	return _usuario;
}

void SaIoTDeviceLib::setUserPassword(String password){

}

String SaIoTDeviceLib::getUserPassword(void){
	return _senhaUsuario;
}*/