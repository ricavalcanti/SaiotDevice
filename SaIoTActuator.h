#ifndef SaIoTActuator_h
#define SaIoTActuator_h

#include<Arduino.h>

class SaIoTActuator{
    private:
      String key = "Not setted", type = "Not setted", label = "Not setted";
      double min=0,max=1,step=0.01;
      void *(actionToBeExec)(String);
    public:
        void setKey(String _key);
        String getKey(void);

        void setType(String _type);
        String getType(void);

        void setLabel(String _label);
        String getLabel(void);

        void setInterval(double _min,double _step,double _max);
        
        void setMin(double _min);
        double getMin(void);
        
        void setMax(double _max);
        double getMax(void);
        
        void setStep(double _step);
        double getStep(void);
};
#endif