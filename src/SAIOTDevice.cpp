#include "SAIOTDevice.h"

void SAIOTDevice::setDevice(deviceType _device){
	if (_device == accum){
		type = accum;
		AccumData device;
	}else if (_device == intens){
		type = intens;
		IntensityDevice device;
	}else if (_device == instant){
		type = instant;
		InstantData device;
	}else{
		Serial.print(F("[SAIOT] ERROR! invalid device type"));
	}
}

void SAIOTDevice::startWifi(){
	//Uncoment to always open mode AP
	//wifi.startConfigPortal();
	wifi.autoConnect();
	Serial.print(F("[SAIOT] connected to "));
	Serial.println(F(WiFi.SSID()));
}

void SAIOTDevice::setSendingEvent(String sendingEventName){
	sendingEvent = sendingEventName;
}

void SAIOTDevice::setReceivingEvent(String receivingEventName){
	receivingEvent = receivingEventName;
}

void setReceivingConfigEvent(String receivingConfigEventName){
	receivingConfigEvent = receivingConfigEventName;
}
void setOnOffEvent(String onOffEventName){
	onOffEvent = onOffEventName;
}

void SAIOTDevice::deviceHandle(){
	if (protocol == ws){
		client.monitor();
	} else if (protocol == mqtt){
		 client.loop();
	}/*else{ 
		implementar http
	}*/
}

String SAIOTDevice::getDeviceJson(AccumData _device){
	StaticJsonBuffer<MAX_JSON_SIZE> jsonBuffer;
	JsonObject &clientData = jsonBuffer.createObject();

	clientData["deviceId"] = _device.getId();
	clientData["ip"] = _device.getDeviceIp();
	clientData["tag"] = _device.getTag();
	clientData["communicationType"] = _device.getCommType();
	clientData["description"] = _device.getDescription();
	clientData["timeout"] = _device.getTimeout();
	clientData["state"] = _device.getState();
	clientData["consumption"] = _device.getConsumption();
	clientData["dateTime"] = _device.getDateTime();
	clientData["actionAdress"] = _device.getActionAdress();
	clientData["deadBand"] = _device.getDeadBand();

	clientData.printTo(devStatus);
	Serial.print(F("[SAIOT] JSON setup: "));
	Serial.println(devStatus);
	return devStatus;
}

String SAIOTDevice::getDeviceJson(IntensityDevice _device){
	StaticJsonBuffer<MAX_JSON_SIZE> jsonBuffer;
	JsonObject &clientData = jsonBuffer.createObject();

	clientData["deviceId"] = _device.getId();
	clientData["ip"] = _device.getDeviceIp();
	clientData["tag"] = _device.getTag();
	clientData["communicationType"] = _device.getCommType();
	clientData["description"] = _device.getDescription();
	clientData["timeout"] = _device.getTimeout();
	clientData["state"] = _device.getState();
	clientData["value"] = _device.getValue();
	clientData["intensity"] = _device.getIntensity();
	clientData["dateTime"] = _device.getDateTime();
	clientData["actionAdress"] = _device.getActionAdress();
	clientData["deadBand"] = _device.getDeadBand();

	clientData.printTo(devStatus);
	Serial.print(F("[SAIOT] JSON setup: "));
	Serial.println(devStatus);
	return devStatus;
}

String SAIOTDevice::getDeviceJson(InstantData _device){
	StaticJsonBuffer<MAX_JSON_SIZE> jsonBuffer;
	JsonObject &clientData = jsonBuffer.createObject();

	clientData["deviceId"] = _device.getId();
	clientData["ip"] = _device.getDeviceIp();
	clientData["tag"] = _device.getTag();
	clientData["communicationType"] = _device.getCommType();
	clientData["description"] = _device.getDescription();
	clientData["timeout"] = _device.getTimeout();
	clientData["state"] = _device.getState();
	clientData["value"] = _device.getValue();
	clientData["dateTime"] = _device.getDateTime();
	clientData["actionAdress"] = _device.getActionAdress();
	clientData["deadBand"] = _device.getDeadBand();

	clientData.printTo(devStatus);
	Serial.print(F("[SAIOT] JSON setup: "));
	Serial.println(devStatus);
	return devStatus;
}

void SAIOTDevice::sendDeviceStatus(String status){
	if(protocol == ws){
		client.emit(sendingStatusEvent, getDeviceJson());
	}/*else if (protocol == mqtt){
		 implementar
	}else{ 
		implementar http
	}*/
	
}

void SAIOTDevice::turnOnOff(String status){
	if(device.getState() == "off"){
    	device.setState(1);
    	socket.emit(sendDeviceStatus, getDeviceJson());
	}
	else{
		device.setState(0);
    	socket.emit(sendDeviceStatus, getDeviceJson());
	}
}

void SAIOTDevice::changeDeviceConfig(String status){
	/*
	//Receiving Debug
	Serial.print(F("[DEBUG] Recebido do Server: "));
	Serial.println(status);*/
	status.replace("\\\"", "\"");
	/*Serial.println();
	Serial.println(status);
	Serial.println();*/

	StaticJsonBuffer<MAX_JSON_SIZE> jsonBuffer;
	JsonObject& newConfig = jsonBuffer.parseObject(status.c_str());

	//Debug Parse
	char newDevStatus[MAX_JSON_SIZE];
	newConfig.printTo(newDevStatus);
	/*Serial.print(F("[DEBUG] Parse do Server: "));
	Serial.println(newDevStatus);
	Serial.println();*/

  if (!newConfig.success()) {
    Serial.println(F("parseObject() failed"));
    return;
  }

  device.setTag(newConfig["tag"]);
  device.setDescription(newConfig["description"]);
  device.setTimeout(newConfig["timeout"]);
  device.setDeadBand(newConfig["deadBand"]);

   if(newConfig["communicationType"] == "sync"){
		device.setCommType(1);
   }else{
		device.setCommType(0);
   }

   if(type==intens){
	   device.setIntensity(newConfig["intensity"]);
   }

  if(protocol==ws){
	  socket.emit(sendDeviceStatus, getDeviceJson(device));
  }
}

void SAIOTDevice::startWSConnection(String host, String port){
	protocol = ws;

	client.on(receivingEvent,sendDeviceStatus(String status));
	client.on(receivingConfigEvent,changeDeviceConfig(String status));
	client.on(onOffEvent,turnOnOff(String status));

		if (!client.connect(host, port)){
		Serial.println(F("[SAIOT] connection device-server failed"));
		return;
	}else if (client.connected()){
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
