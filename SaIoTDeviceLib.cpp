#include "SaIoTDeviceLib.h"

SaIoTDeviceLib::SaIoTDeviceLib(String _name, String _serial, String _host, String _post, String _erro, int _port)
{
  name = _name;
  serial = _serial;
  host = _host;
  post = _post;
  erro = _erro;
  port = _port;
};
SaIoTDeviceLib::SaIoTDeviceLib(){
};

void SaIoTDeviceLib::start()
{
  //inicia conexão
  WiFiManager wifi;
  
  if (wifi.autoConnect())
  {
      Serial.print(F("[SaIoT] connected to "));
      Serial.println(WiFi.SSID());
  }else{
    Serial.println("Não conseguiu conexão");
  }
  


}

void SaIoTDeviceLib::start(String _serial)
{
  setSerial(_serial);

  //

  WiFiManager wifi;
  wifi.autoConnect();
  Serial.print(F("[SaIoT] connected to "));
  Serial.println(WiFi.SSID());

  String JSON = "{\"dados\":[{\"serial\":\"" + serial + "\"}],\"data_hora\":\"2018-05-30 01:00:01\",\"sinal\":-55,\"codigo\":1,\"mensagem\":\"Reiniciando\",\"ip\":\"192.168.0.59\"}";
  // StaticJsonBuffer<50> jsonBuffer;
  // JsonObject& root = jsonBuffer.createObject();
  // root["serial"] = serial;
  // root.printTo(JSON);
  // Serial.println(JSON); //DEBUG

  // ws = new SocketIOClient;

  // if (!ws->connect(host, port)){
  //   Serial.println(F("[SaIoT] connection device-server failed"));
  //   return;
  // }
  // else if (ws->connected()){
  //   Serial.println(F("[SaIoT] connection device-server established"));
  //   String route = host + erro;
  //   ws->emit(route, JSON);
  // }

  // HTTPClient http;
  // String route = host + erro;
  // Serial.println("----------------------");
  // Serial.println(route);
  // http.begin(route);
  // http.addHeader("Content-Type", "application/json");
  // Serial.println(http.POST(JSON));
  // String payload = "Payload: " + http.getString();
  // http.end();
  // Serial.flush();
}

void SaIoTDeviceLib::start(String _serial, protocol _protocol, String _host, int _port)
{
  setSerial(_serial);
  setHost(_host);
  setPort(_port);

  WiFiManager wifi;
  wifi.autoConnect();
  // wifi.autoConnect(getSerial());
  // Serial.print(F("[SaIoT] connected to "));
  // Serial.println(WiFi.SSID());

  String JSON;
  StaticJsonBuffer<50> jsonBuffer;
  JsonObject &root = jsonBuffer.createObject();
  root["serial"] = serial;
  root.printTo(JSON);

  // Serial.println(JSON); //DEBUG

  // ws = new SocketIOClient;
  /*
      aqui vai a parte do vetor de ponteiros
      para atribuição do on
      */
  // for (int i = 0; i < qtdControllers; ++i){
  //paranauê dos json (a definir);

  //ws.on(variave_contendo_keys,ponteiro_da_funcao);
  // ws->on("atuar", callback);
  // }

  // if (!ws->conn\
  /*
  // break;

  //  case HTTP:
  //    Serial.println(F("[SaIoT] HTTP choosed - not setted"));
  //    break;
  // case MQTT:
  //   WiFiClient espClient;
  //   mqttClient = new PubSubClient;
  //   mqttClient->setClient(espClient);
  //   mqttClient->setServer(_host, _port);
  //   for (int i = 0; i < qtdControllers; ++i){
  //paranauê dos json (a definir);
  //ws.on(variave_contendo_keys,ponteiro_da_funcao);
  // ws->on("atuar", callback);
  // }

  //   mqttClient->connect(_serial);
  //   if (!(mqttClient->connected())){
  //     Serial.println(F("[SaIoT] connection device-server failed"));
  //     return;
  //   }
  //   else if (mqttClient->connected()){
  //     Serial.println(F("[SaIoT] connection device-server established"));
  //     mqttClient->publish(post, JSON.c_str());
  //   }
  //   Serial.flush();
  //   break;
  // }
  // */
}

void SaIoTDeviceLib::setName(String _name)
{
  // size_t index = 0;//testar byte;
  // while(*_name)
  // {
  //   name[index++] = *_name;
  //   *_name++;
  // }
  name = _name;
}
String SaIoTDeviceLib::getName(void)
{
  return name;
}

void SaIoTDeviceLib::setSerial(String _serial)
{
  // size_t index = 0;//testar byte;
  // while(*_serial){
  //   serial[index++] = *_serial++;
  // }
  serial = _serial;
}
String SaIoTDeviceLib::getSerial(void)
{
  return serial;
}

void SaIoTDeviceLib::setHost(String _host)
{
  // size_t index = 0;//testar byte;
  //  while(*_host)
  //  {
  //    host[index++] = *_host++;
  //    // _ip++;
  //  }
  host = _host;
}

String SaIoTDeviceLib::getHost(void)
{
  return host;
}

void SaIoTDeviceLib::setPort(int _port)
{
  port = _port;
}

int SaIoTDeviceLib::getPort(void)
{
  return port;
}

void SaIoTDeviceLib::addSensor(SaIoTSensor *newSensor)
{
  sensors[sensorIndex++] = newSensor;
}
void SaIoTDeviceLib::addSensor(String _key, String _unit)
{
  sensors[sensorIndex++] = new SaIoTSensor(_key, _unit);
}
void SaIoTDeviceLib::addSensor(String _key, int _deadbandMin, int _deadbandMax, int _timeout, int _resolution, bool _isAcumm, String _tag, String _unit)
{
  sensors[sensorIndex++] = new SaIoTSensor(_key, _deadbandMin, _deadbandMax, _timeout, _resolution, _isAcumm, _tag, _unit);
}

/*void SaIoTDeviceLib::addController(SaIoTController *newController)
{
  controllers[controllerIndex++] = newController;
}
void SaIoTDeviceLib::addController(String _key, String _type)
{
  controllers[controllerIndex++] = new SaIoTController(_key, _type);
}
void SaIoTDeviceLib::addController(String _key, String _type, String _tag, String _description, double _min, double _step, double _max)
{
  controllers[controllerIndex++] = new SaIoTController(_key, _type, _tag, _description, _min, _step, _max);
}*/

// void SaIoTDeviceLib::setUser(String user){
//   _usuario = user;
// }

// String SaIoTDeviceLib::getUser(void){
//   return _usuario;
// }

// void SaIoTDeviceLib::setUserPassword(String password){

// }

// String SaIoTDeviceLib::getUserPassword(void){
//   return _senhaUsuario;
// }
// void SaIoTDeviceLib::setProtocol(protocol protocolType){
//  _protocol = protocolType;
// }
//
// protocol SaIoTDeviceLib::getProtocol(void){
//  return _protocol;
// }

// String SaIoTDeviceLib::getSensors(void){
//  return sensor;
// }

// void SaIoTDeviceLib::setControler(String _controler){

// }

// String SaIoTDeviceLib::getControler(void){

// }
