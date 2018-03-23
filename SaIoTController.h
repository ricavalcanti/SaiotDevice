#ifndef SaIoTController_h
#define SaIoTController_h

#include<Arduino.h>


class SaIoTController{
    private:
      char key[5] = "";
      char type[20] = "";
      char label[50] = "Not setted";

      double min=0,max=1,step=0.01;
    public:
        SaIoTController();
        SaIoTController(String _key, String _type, String _label, double _min, double _step, double _max);
        ~SaIoTController();

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
