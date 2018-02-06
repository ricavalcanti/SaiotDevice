#ifndef SaiotDevice_h
#define SaiotDevice_h

#include <Arduino.h>
#include "thirdyPartyLibs/WiFiManager/WiFiManager.h"
#include "thirdyPartyLibs/ArduinoJson/ArduinoJson.h"

#include "thirdyPartyLibs/SocketIOClient/SocketIOClient.h"
#include "thirdyPartyLibs/pubsubclient/src/PubSubClient.h"

//Additional libs for each type of device
#include "thirdyPartyLibs/deviceData/AccumData.h"
#include "thirdyPartyLibs/deviceData/IntensityDevice.h"
#include "thirdyPartyLibs/deviceData/InstantData.h"

#define MAX_JSON_SIZE 400

enum deviceType{
    accum,
    intens,
    instant,
};

enum protocolType{
    ws,
    mqtt,
    http,
};

typedef void (*behaviorChangeFunction)(int timeout, int port, String deviceJson);

class SaiotDevice{
  private:
    WiFiManager wifi;
    protocolType protocol;
    deviceType type;

    AccumData accumDevice;
    IntensityDevice intDevice;
    InstantData instDevice;

    SocketIOClient client;
    //PubSubClient client(espClient);

    char devStatus[MAX_JSON_SIZE];

    String sendingStatusEvent = "device_send";
    String receivingStatusEvent = "device_on";
    String receivingConfigEvent = "device_config";
    String onOffEvent = "device_onOff";

    behaviorChangeFunction = defaultBehaviorfunction;

  public:
    void setDevice(deviceType device);
    void startWifi();

    void setSendingEvent(String sendingEventName);
    void setReceivingEvent(String receivingEventName);
    void setReceivingConfigEvent(String receivingConfigEventName);
    void setOnOffEvent(String onOffEventName);

    void setDeviceBehavior(behaviorChangeFunction _function);
    void defaultBehaviorfunction(int timeout, int port, String deviceJson);

    void startWSConnection(String host, int port);
    //void startMQTTConnection(String host, String port);
    //void startHTTPConnection(String host, String port);

    void deviceHandle();

    String getDeviceJson(AccumData _device);
    String getDeviceJson(IntensityDevice _device);
    String getDeviceJson(InstantData _device);

    void sendDeviceStatus(String status);
    void turnOnOff(String status);
    void changeDeviceConfig(String status);

    //void interruptToRead(port, function1, function2, timeout)
    //void interruptToRead(function1,timeout)
    //void verify(function1)

};

#endif
