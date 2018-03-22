#ifndef SaIoTSensor_h
#define SaIoTSensor_h

#include<Arduino.h>

class SaIoTSensor{
    private:
        char key[50] =  "Not setted";
        char label[50] = "Not setted";
        char unit[50] = "Not setted";

        unsigned long int deadband = 0, timeout = 0, lastTimeout = 0, lastResolution = 0,resolution = 0;
        double valor;
        bool isAcumm = false, isSync = true, isDigital=true;
        typedef void (*verifyfunct)(void);
    public:
        /****************************************************************
         * Sensor JSON Functions
        ****************************************************************/
        void setKey(String _key);
        String getKey(void);

        void setSyncCommunication(bool _isSync);
        bool isSyncCommunication(void);

        void setDeadBand(int _deadband);
        int getDeadBand(void);

        void setTimeout(int _timeout);
        int getTimeout(void);

        void setDigitalDevice(bool _isDigital);
        bool isDigitalDevice(void);

        void setAcummulate(bool _isAcummulate);
        bool isAcummulate(void);

        void setLabel(String _label);
        String getLabel(void);

        void setValor(double _valor);
        double getValor(void);

        void setUnit(String _unit);
        String getUnit(void);

        void setResolution(unsigned long _resolution);
        unsigned long getResolution(void);

        // /****************************************************************
        //  * Sensor Reading Functions: Verification and interruptions
        // ****************************************************************/
        void verify(void);

        /* envia ao servidor o json com as informações da leitura do sensor*/
        int send(void);
};

#endif
