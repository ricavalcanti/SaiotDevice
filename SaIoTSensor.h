#ifndef SaIoTSensor_h
#define SaIoTSensor_h

#include<Arduino.h>

class SaIoTSensor{
    private:
        String key;
        String tag;
        String unit;

        unsigned long int deadbandMin = 0,
        deadbandMax = 0,
        timeout = 5000,/* 5 segundos = 5 * 1000 milissegundos */
        lastTimeout = 0,
        lastResolution = 0,
        resolution = 0;
        double valor;
        bool isAcumm = true/*, isSync = true, isDigital=true*/;
        // typedef void (*verifyfunct)(void);
    public:
        SaIoTSensor();
        SaIoTSensor(String _key, int _deadbandMin, int _deadbandMax, int _timeout, int _resolution,  bool _isAcumm, String _tag, String _unit);
        SaIoTSensor(String _key, String _unit);
        ~SaIoTSensor();
        
        /*****************************************************************************************************************************************************
         * Sensor JSON Functions
        ******************************************************************************************************************************************************/
        void setKey(String _key);
        String getKey(void);

        void setSyncCommunication(bool _isSync);
        bool isSyncCommunication(void);

        void setDeadBandMin(int _deadbandMin);
        int  getDeadBandMin(void);
        void setDeadBandMax(int _deadbandMax);
        int  getDeadBandMax(void);

        void setTimeout(int _timeout);
        int getTimeout(void);

        // void setDigitalDevice(bool _isDigital);
        // bool isDigitalDevice(void);

        void setAcummulate(bool _isAcummulate);
        bool isAcummulate(void);

        void setTag(String _keytag);
        String getTag(void);

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
