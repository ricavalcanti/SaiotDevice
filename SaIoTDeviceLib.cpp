#include"SaIoTDeviceLib.h"

void SaIoTDeviceLib::start(char* _serial, protocol _protocol, char* _host, int _port, char* post){
  setSerial(_serial);
  setHost(_host);
  setPort(_port);
  
  // switch(_protocol){
  //  case WS:
    //  break;
    // case HTTP:
    //  Serial.println(F("[SaIoT] HTTP choosed - not setted"));
    //  // httpClient = new httpClient;
    //  break;
    // case MQTT:
    //  Serial.println(F("[SaIoT] MQTT choosed - not setted"));
    //  break;
    // }

  //Uncoment to always open mode AP
  //wifi.startConfigPortal();
  WiFiManager wifi;
  wifi.autoConnect(_serial);
  Serial.print(F("[SaIoT] connected to "));
  Serial.println(WiFi.SSID());


  String JSON;
  StaticJsonBuffer<50> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["serial"] = serial;
  root.printTo(JSON);
  
  Serial.println(JSON); //DEBUG
  
  switch(_protocol){
    case WS:
      ws = new SocketIOClient;
      /*
      aqui vai a parte do vetor de ponteiros
      para atribuição do on
      */
      for (int i = 0; i < qtdControllers; ++i){
       //paranauê dos json (a definir);



       //ws.on(variave_contendo_keys,ponteiro_da_funcao);
      // ws->on("atuar", callback);
      }

      if (!ws->connect(_host, _port)){
        Serial.println(F("[SaIoT] connection device-server failed"));
        return;
      }
      else if (ws->connected()){
        Serial.println(F("[SaIoT] connection device-server established"));
        ws->emit(post, JSON);
      }
      Serial.flush();
      break;

  //  case HTTP:
  //    Serial.println(F("[SaIoT] HTTP choosed - not setted"));
  //    break;
    case MQTT:
      WiFiClient espClient;
      mqttClient = new PubSubClient;
      mqttClient->setClient(espClient);
      mqttClient->setServer(_host, _port);
      for (int i = 0; i < qtdControllers; ++i){
      //paranauê dos json (a definir);
      //ws.on(variave_contendo_keys,ponteiro_da_funcao);
      // ws->on("atuar", callback);
      }

    mqttClient->connect(_serial);
    if (!(mqttClient->connected())){
      Serial.println(F("[SaIoT] connection device-server failed"));
      return;
    }
    else if (mqttClient->connected()){
      Serial.println(F("[SaIoT] connection device-server established"));
      mqttClient->publish(post, JSON.c_str());
    }
    Serial.flush();
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

void SaIoTDeviceLib::setName(char* _name){
  size_t index = 0;//testar byte;
  while(*_name)
  {
    name[index++] = *_name;
    *_name++;
  }
}
char* SaIoTDeviceLib::getName(void){
  return name;
}

void SaIoTDeviceLib::setSerial(char* _serial){
  size_t index = 0;//testar byte;
  while(*_serial){
    serial[index++] = *_serial++;
  }
}
char* SaIoTDeviceLib::getSerial(void){
  return serial;
}

void SaIoTDeviceLib::setIp(char* _ip){
 size_t index = 0;//testar byte;
  while(*_ip)
  {
    ip[index++] = *_ip++;
    // _ip++;
  }
}

char* SaIoTDeviceLib::getIp(void){
 return ip;
}

void SaIoTDeviceLib::setHost(char* _host){
 size_t index = 0;//testar byte;
  while(*_host)
  {
    host[index++] = *_host++;
    // _ip++;
  }
}

char* SaIoTDeviceLib::getHost(void){
 return host;
}

void SaIoTDeviceLib::setPort(int _port){
  port = _port;
}

int SaIoTDeviceLib::getPort(void){
 return port;
}

void SaIoTDeviceLib::addSensor(String _key, bool _isSync, int _deadband, int _timeout, bool _isDigital, bool _isAcumm, String _label, double _valor, String _unit){
  sensor[qtdSensors++] = new SaIoTSensor( _key,_isSync,_deadband,_timeout,_isDigital,_isAcumm,_label,_valor,_unit);
 }

void SaIoTDeviceLib::addController(String _key, String _type, String _label, double _min, double _step, double _max){
  controllers[qtdControllers++] = new SaIoTController(_key, _type, _label, _min, _step, _max);
 }
 


// void SaIoTDeviceLib::setUser(char* user){
//   _usuario = user;
// }

// char* SaIoTDeviceLib::getUser(void){
//   return _usuario;
// }

// void SaIoTDeviceLib::setUserPassword(char* password){

// }

// char* SaIoTDeviceLib::getUserPassword(void){
//   return _senhaUsuario;
// }
// void SaIoTDeviceLib::setProtocol(protocol protocolType){
//  _protocol = protocolType;
// }
//
// protocol SaIoTDeviceLib::getProtocol(void){
//  return _protocol;
// }

// char* SaIoTDeviceLib::getSensors(void){
//  return sensor;
// }

// void SaIoTDeviceLib::setControler(char* _controler){

// }

// char* SaIoTDeviceLib::getControler(void){

// }
