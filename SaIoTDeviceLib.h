#ifndef SaIoTDeviceLib_h
#define SaIoTDeviceLib_h

#include <Arduino.h>
#include <WiFiManager.h>
#include<SocketIOClient.h>

//TENTATIVA DE INCLUIR .hs DE OUTROS DIRETÓRIOS
//#include "./WiFiManager/WiFiManager.h"
//#include "./SocketIOClient/SocketIOClient.h"

//#include "thirdyPartyLibs/WiFiManager/WiFiManager.h"
//#include "thirdyPartyLibs/SocketIOClient/SocketIOClient.h"

#include "./thirdyPartyLibs/ArduinoJson/ArduinoJson.h"
#include "./thirdyPartyLibs/pubsubclient/src/PubSubClient.h"

#include "SaIoTSensor.h"
#include "SaIoTActuator.h"

enum protocol{
  WS,
  MQTT,
  HTTP
};

class SaIoTDeviceLib {
  private:
    WiFiManager wifi;
    SocketIOClient wsClient;

    String serial = "Not setted",ip =  "Not setted", name =  "Not setted", sensor = "not setted";
    protocol _protocol = WS;
  public:
    void start(int boundRate);
    void connect(String host, int port);

    void setName(String _name);
    String getName(void);
    
    void setSerial(String _serial);
    String getSerial(void);
    
    void setIp(String _ip);
    String getIp(void);
    
    void setProtocol(protocol _protocol);
    protocol getProtocol(void);
    
    void setSensors(String _sensor);
    String getSensors(void);

    void setControler(String _controler);
    String getControler(void);

    void handle(void);

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
