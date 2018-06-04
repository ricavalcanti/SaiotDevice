#ifndef SaIoTDeviceLib_h
#define SaIoTDeviceLib_h
//ESPERANDO ATUALIZAÇÃO DOS SENSOR POR PATRICIO
#include <Arduino.h>
#include <WiFiManager.h>
#include <SocketIOClient.h>
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>
// #include <PubSubClient.h> //https://pubsubclient.knolleary.net/api.html

#include "SaIoTSensor.h"
#include "SaIoTController.h"

#ifndef qtdSensors
#define qtdSensors 1
#endif
#ifndef qtdControllers
#define qtdControllers 1
#endif

enum protocol
{
  WS,
  MQTT,
  HTTP
};
typedef void (*fncpt)(String);
class SaIoTDeviceLib
{
private:
  SocketIOClient *ws;
  // WiFiClient espClient;
  // PubSubClient *mqttClient;
  // HTTPClient *http;

  String name;
  String serial;
  String host;
  String post;
  String erro;
  int port = 80;
  protocol _protocol = WS; //olhar dps

  unsigned int sensorIndex = 0;
  unsigned int controllerIndex = 0;
  SaIoTSensor *sensors[qtdSensors];
  SaIoTController *controllers[qtdControllers];

public:
  /* criar um construtor  e passar a start para o produto talvez*/
  //Editar após discussão de conexão
  SaIoTDeviceLib(String _name, String _serial, String _host, String _post, String _erro, int _port);
  SaIoTDeviceLib();

  void start();
  void start(String serial);
  void start(String serial, protocol _protocol, String _host, int _port);

  void setName(String _name);
  String getName(void);

  void setSerial(String _serial);
  String getSerial(void);

  void setHost(String _host);
  String getHost(void);

  void setPort(int _port);
  int getPort(void);

  void addSensor(SaIoTSensor *newSensor);
  void addSensor(String _key, int _deadbandMin, int _deadbandMax, int _timeout, int _resolution, bool _isAcumm, String _label, String _unit);
  void addSensor(String _key, String _unit);

  void addController(SaIoTController *newController);
  void addController(String _key, String _type);
  void addController(String _key, String _type, String _tag, String _description, double _min, double _step, double _max);
  // String getSensors(void);

  // void setProtocol(protocol _protocol);
  // protocol getProtocol(void);

  //WifiManager - SaIoT

  //void setUser(String user);
  //String getUser(void);

  //void setUserPassword(String password);
  //String getUserPassword(void);

  //void setCentral(String central); perguntar o que é
  //void setSincrono(bool sincrono); está no sensor
  //void setTempoEnvio(int tempoEnvio); //timeout, está no sensor*/
};

#endif

/*String _usuario;
String _senhaUsuario;
String _central;
    int    _inicioMemoria;
    int    _tamanhoMemoria;
    bool   _sincrono; //true == sincrono && false == assincrono
    int    _tempoEnvio;*/
