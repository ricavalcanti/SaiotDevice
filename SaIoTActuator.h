#ifndef SaIoTActuator_h
#define SaIoTActuator_h

#include<Arduino.h>

class SaIoTSensor{
    private:
      String key = "Not setted", type = "Not setted", label = "Not setted";
      double min=0,max=1,step=0.01;
    public:
        void setKey(String _key);
        String getKey(void);

        void setType(String _type);
        String getType(void);

        void setLabel(String _label);
        String getLabel(void);

        void setInterval(double _min,double _step,double _max);
        void setMin(double _min);
        void setMax(double _max);
        void setStep(double _step);
        double getMin(void);
        double getMax(void);
        double getStep(void);

        void act(void (*actionToBeExec)(String));
};
#endif