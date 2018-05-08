/*#ifndef SaIoTController_h
#define SaIoTController_h

#include<Arduino.h>


class SaIoTController{
    private:
      char key[5] = "";
      char type[20] = "";
      char tag[50] = "Not setted";
      char description[150] ="Not setted";

      //VAI CONTINUAR TENDO ESSAS VARIÁVEIS NO CONTROLLER?
      //double min=0,max=1,step=0.01;
    public:
        SaIoTController();
        SaIoTController(String _key, String _type, String _tag, String _description); //, double _min, double _step, double _max);
        ~SaIoTController();

        void setKey(String _key);
        String getKey(void);

        void setType(String _type);
        String getType(void);

        void setTag(String _tag);
        String getTag(void);

        void setDescription(String _description);
        String getDescription(void);

        // void setInterval(double _min,double _step,double _max);

        // void setMin(double _min);
        // double getMin(void);

        // void setMax(double _max);
        // double getMax(void);

        // void setStep(double _step);
        // double getStep(void);
};
#endif
*/
