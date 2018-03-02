#ifndef SaIoTActuator_h
#define SaIoTActuator_h

#include<Arduino.h>

class SaIoTSensor{
    private:
      String key = "Not setted", type = "Not setted", label = "Not setted";
      int min,max,step;
    public:
        void setKey(String _key);
        String getKey(void);

        void setType(String _type);
        String getType(void);

        void setLabel(String _label);
        String getLabel(void);

        void setInterval(int _min,int _step,int _max);
        void setMin(int _min);
        void setMax(int _max);
        void setStep(int _step);
        int getMin(void);
        int getMax(void);
        int getStep(void);

        void act(/*function*/);
};
#endif