#include"SaIoTDeviceLib.h"

void SaIoTDeviceLib::start(char* _serial, protocol _protocol, char* host, int port, char* post){
  setSerial(_serial);
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
// }

// void SaIoTDeviceLib::connect(char* host, int port, char* post, fncpt callback){
  String JSON;
  StaticJsonBuffer<50> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["serial"] = serial;
  root.printTo(JSON);
  Serial.println(JSON);
  switch(_protocol){
    case WS:
      ws = new SocketIOClient;
      /*
      aqui vai a parte do vetor de ponteiros
      para atribuição do on
      */
      for (int i = 0; i < qtdControllers; ++i)
      {
       //paranauê dos json (a definir);
       //ws.on(variave_contendo_keys,ponteiro_da_funcao);
      // ws->on("atuar", callback);
      }

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
  //
  //  case HTTP:
  //    Serial.println(F("[SaIoT] HTTP choosed - not setted"));
  //    break;
  //  case MQTT:
  //    Serial.println(F("[SaIoT] MQTT choosed - not setted"));
  //    break;
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

// void SaIoTDeviceLib::setSensors(char* _sensor){
//  sensor = _sensor;
// }

// char* SaIoTDeviceLib::getSensors(void){
//  return sensor;
// }

// void SaIoTDeviceLib::setControler(char* _controler){

// }

// char* SaIoTDeviceLib::getControler(void){

// }

