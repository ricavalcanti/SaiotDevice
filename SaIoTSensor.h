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
        
};

#endif