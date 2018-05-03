#ifndef SaIoTDeviceLib_h
#define SaIoTDeviceLib_h

#include <Arduino.h>
#include <WiFiManager.h>
#include <SocketIOClient.h>
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>
// #include <PubSubClient.h> //https://pubsubclient.knolleary.net/api.html

#include "SaIoTSensor.h"
// #include "SaIoTController.h"
#define qtdSensors 1


enum protocol{
  WS,
  MQTT,
  HTTP
};
typedef void (*fncpt)(String);
class SaIoTDeviceLib {
  private:

    SocketIOClient *ws;
    // WiFiClient espClient;
    // PubSubClient *mqttClient;
    // HTTPClient *http;

    String serial = "";
    String ip =  "";
    String name =  "";
    String host = "http://api.saiot.ect.ufrn.br";
    String post = "/v1/history/hidrometro/";
    String erro = "/v1/history/erro/";
    int port = 80;
    protocol _protocol = WS;
    
    // unsigned char qtdControllers = 1;
    unsigned int sensorIndex = 0;
    SaIoTSensor* sensors[qtdSensors];
    //SaIoTController controllers[qtdControllers];
  public:
    /* criar um construtor  e passar a start para o produto talvez*/
    void start(String serial);
    void start(String serial, protocol _protocol, String _host, int _port);
    void handle(void);

    void setName(String _name);
    String getName(void);

    void setSerial(String _serial);
    String getSerial(void);

    // void setIp(String _ip);
    // String getIp(void);

    void setHost(String _host);
    String getHost(void);

    void setPort(int _port);
    int getPort(void);

    void addSensor(String _key, int _deadbandMin, int _deadbandMax , int _timeout, int _resolution, bool _isAcumm, String _label, String _unit);
    // String getSensors(void);

    // void setControler(String _controler);
    // String getControler(void);
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
