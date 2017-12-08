#ifndef SAIOTDevice_h
#define SAIOTDevice_h

#include "ArduinoJson.h"
#include "SocketIOClient.h"
#include "WifiManager.h"


//COMO SOH ATIVAR O .H DO DISPOSITIVO ESPECIFICO?
#include "AccumData.h"
#include "IntensityDevice.h"
#include "InstantData.h"

class SAIOTDevice{
    private:
        SocketIOClient client;
        WiFiManager wifi;

        //possiveis tipos de dispositivos
        AccumData AccumDevice;
        IntensityDevice IntDevice;
        InstantData InstantDevice;
    public:
        void setDevice(String type);
        void startWSConnection(String host, String port);
        //void startHTTPConnection(String host, String port);
        //void startMQTTConnection(String host, String port);
        void startWifi();
        void deviceHandle();
};

#endif
