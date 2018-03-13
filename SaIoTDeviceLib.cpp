#include"SaIoTDeviceLib.h"

void SaIoTDeviceLib::start(String _serial,int boundRate){
	// setSerial(_serial);
	Serial.begin(boundRate);
	
	switch(_protocol){
		case WS:
			ws = new SocketIOClient;
			break;
		case HTTP:
			httpClient = new httpClient;
			break;
		case MQTT:
			Serial.println(F("[SaIoT] MQTT choosed - not setted"));
			break;
		}

  //Uncoment to always open mode AP
	//wifi.startConfigPortal();
	WiFiManager wifi;
	wifi.autoConnect();
	Serial.print(F("[SaIoT] connected to "));
 	Serial.println(WiFi.SSID());
}

void SaIoTDeviceLib::connect(String host, int port, String post, fncpt callback){
	String JSON;
  	StaticJsonBuffer<50> jsonBuffer;
  	JsonObject& root = jsonBuffer.createObject();
  	root["serial"] = serial;
  	root.printTo(JSON);
  	Serial.println(JSON);
  	switch(_protocol){
		case WS:
		/*
		aqui vai a parte do vetor de ponteiros
		para atribuição do on
		*/
		// for (int i = 0; i < qtdControllers; ++i)
		// {
		// 	//paranauê dos json (a definir);
		// 	//ws.on(variave_contendo_keys,ponteiro_da_funcao);
		// }
		ws->on("atuar", callback);

		if (!ws->connect(host, port)){
			Serial.println(F("[SaIoT] connection device-server failed"));
			return;
		}
		else if (ws->connected()){
			Serial.println(F("[SaIoT] connection device-server established"));
			ws->emit(post, JSON);
		}
		Serial.flush();
		break;

		case HTTP:
			Serial.println(F("[SaIoT] HTTP choosed - not setted"));
			break;
		case MQTT:
			Serial.println(F("[SaIoT] MQTT choosed - not setted"));
			break;
	}
}

void SaIoTDeviceLib::handle(void){
	switch(_protocol){
		case WS:
			ws->monitor();
			break;
		case HTTP: Serial.println(F("[SaIoT] HTTP loop - not setted"));
		case MQTT: Serial.println(F("[SaIoT] MQTT loop - not setted"));
	}
}

// void SaIoTDeviceLib::setName(String _name){
// 	name = _name;
// 	//name-char _name-string...string -to- char
// }

// String SaIoTDeviceLib::getName(void){
// 	return name;
// }

// void SaIoTDeviceLib::setSerial(String _serial){
// 	serial = _serial;
// 	//serial - char / _serial - string...string -to- char
// }
// }

// String SaIoTDeviceLib::getSerial(void){
// 	return serial;
// }

// void SaIoTDeviceLib::setIp(String _ip){
// 	ip = _ip;
// 	//ip - char  / _ip - string...string -to- char
// }
// }

// String SaIoTDeviceLib::getIp(void){
// 	return ip;
// }

// void SaIoTDeviceLib::setProtocol(protocol protocolType){
// 	_protocol = protocolType;
// }

// protocol SaIoTDeviceLib::getProtocol(void){
// 	return _protocol;
// }

// void SaIoTDeviceLib::setSensors(String _sensor){
// 	// sensor = _sensor;
// 	//sensor-* / _name-string... ???typedef void (*fncpt)(String)???
// }


// String SaIoTDeviceLib::getSensors(void){
// 	return sensor;
// }

// void SaIoTDeviceLib::setControler(String _controler){

// }

// String SaIoTDeviceLib::getControler(void){

// }

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
