#ifndef SaIoTDeviceLib_h
#define SaIoTDeviceLib_h

#include <Arduino.h>
#include <WiFiManager.h>
#include <SocketIOClient.h>
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>

#include "SaIoTSensor.h"

enum protocol{
  WS,
  MQTT,
  HTTP
};
typedef void (*fncpt)(String);
class SaIoTDeviceLib {
  private:

    SocketIOClient *ws;
    HTTPClient *http;
    
    SaIoTSensor *sensors;
    SaIoTActuator *actuators;

    char serial[50] = "Not setted";
    char ip[50] =  "Not setted";
    char name[50] =  "Not setted";
    protocol _protocol = WS;
  public:
    void start(String serial,int boundRate);
    void connect(String host, int port, String post, fncpt callback);
    void handle(void);


    // void setName(String _name);
    // String getName(void);

    // void setSerial(String _serial);
    // String getSerial(void);

    // void setIp(String _ip);
    // String getIp(void);

    // void setProtocol(protocol _protocol);
    // protocol getProtocol(void);

    // /*void setSensors(String _sensor);
    // String getSensors(void);

    // void setControler(String _controler);
    // String getControler(void);*/


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
