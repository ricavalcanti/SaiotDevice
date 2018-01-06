#ifndef SAIOTDevice_h
#define SAIOTDevice_h

#include <Arduino.h>
#include "thirdyPartyLibs/WiFiManager/WiFiManager.h"
#include "thirdyPartyLibs/ArduinoJson/ArduinoJson.h"

#include "thirdyPartyLibs/SocketIOClient/SocketIOClient.h"
#include "thirdyPartyLibs/pubsubclient/src/PubSubClient.h"

//Additional libs for each type of device
#include "thirdyPartyLibs/deviceData/AccumData.h"
#include "thirdyPartyLibs/deviceData/IntensityDevice.h"
#include "thirdyPartyLibs/deviceData/InstantData.h"

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

class SAIOTDevice{
    private:
        WiFiManager wifi;
        SocketIOClient client;
        //PubSubClient client(espClient);
        protocolType protocol;

    public:
        void setDevice(deviceType device);
        void setDeviceJson();
        void startWifi();
        void startWSConnection(String host, String port);
        //void startMQTTConnection(String host, String port);
        //void startHTTPConnection(String host, String port);
        void deviceHandle();
};

#endif
