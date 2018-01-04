#ifndef SAIOTDevice_h
#define SAIOTDevice_h

#include <Arduino.h>
#include "WifiManager.h"
#include "ArduinoJson.h"

#include "SocketIOClient.h"
#include "PubSubClient.h"

#include "DeviceData.h"
//Additional libs for each type of device
#include "AccumData.h"
#include "IntensityDevice.h"
#include "InstantData.h"

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
        PubSubClient client(espClient);
        protocolType protocol;

    public:
        void setDevice(deviceType device);
        void setDeviceJson();
        void startWifi();
        void startWSConnection(String host, String port);
        void startMQTTConnection(String host, String port);
        //void startHTTPConnection(String host, String port);
        void deviceHandle();
};

#endif
