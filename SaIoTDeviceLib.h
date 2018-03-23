#ifndef SaIoTDeviceLib_h
#define SaIoTDeviceLib_h

#include <Arduino.h>
#include <WiFiManager.h>
#include <SocketIOClient.h>
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>
#include <PubSubClient.h> //https://pubsubclient.knolleary.net/api.html

#include "SaIoTSensor.h"
#include "SaIoTController.h"

enum protocol{
  WS,
  MQTT,
  HTTP
};
typedef void (*fncpt)(char*);
class SaIoTDeviceLib {
  private:

    SocketIOClient *ws;
    WiFiClient espClient;
    PubSubClient *mqttClient;
    // HTTPClient *http;

    char serial[50] = "Not setted";
    char ip[50] =  "Not setted";
    char name[50] =  "Not setted";
    char host[20] = "Not Setted";
    int port = 0;
    protocol _protocol = WS;
    unsigned char qtdSensors = 1;
    unsigned char qtdControllers = 1;
    SaIoTSensor sensors[qtdSensors];
    //SaIoTController controllers[qtdControllers];
  public:
    void start(char* serial, protocol _protocol, char* _host, int _port, char* post);
    void handle(void);

    void setName(char* _name);
    char* getName(void);

    void setSerial(char* _serial);
    char* getSerial(void);

    void setIp(char* _ip);
    char* getIp(void);

    void setHost(char* _host);
    char* getHost(void);

    void setPort(int _port);
    int getPort(void);

    void addSensors(String _key, bool _isSync, int _deadband, int _timeout, bool _isDigital, bool _isAcumm, String _label, double _valor, String _unit);
    // char* getSensors(void);

    // void setControler(char* _controler);
    // char* getControler(void);
    // void setProtocol(protocol _protocol);
    // protocol getProtocol(void);



  //WifiManager - SaIoT

    //void setUser(char* user);
    //char* getUser(void);

    //void setUserPassword(char* password);
    //char* getUserPassword(void);


    //void setCentral(char* central); perguntar o que é
    //void setSincrono(bool sincrono); está no sensor
    //void setTempoEnvio(int tempoEnvio); //timeout, está no sensor*/
};

#endif

/*char* _usuario;
char* _senhaUsuario;
char* _central;
    int    _inicioMemoria;
    int    _tamanhoMemoria;
    bool   _sincrono; //true == sincrono && false == assincrono
    int    _tempoEnvio;*/
