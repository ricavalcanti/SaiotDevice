#ifndef SaIoTSensor_h
#define SaIoTSensor_h

#include<Arduino.h>

class SaIoTSensor{
    public:
        String key =  "Not setted", label = "Not setted", unit = "not setted";
        int deadband, timeout;
        double valor;
        bool isAcumm = false, isSync = true, isDigital=true;
    private:
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

        /****************************************************************
         * Sensor Reading Functions: Verification and interruptions
        ****************************************************************/
        void verify(/*function as a parameter*/);
        // void interruptToRead(/*String port,function,change*/); //Timeout já setado no JSON;
        // void interruptToRead(/*function, int time*/);
};

#endif
