#ifndef SaioTProduct_h
#define SaioTProduct_h



#include <Arduino.h>

#define qtdDevices 1

#include "SaiotDeviceLib.h"
#include "SaIoTSensor.h"
//#include "SaIoTController.h"

class SaIoTProduct {
  private:
  unsigned int deviceIndex = 0;
  SaIoTDeviceLib* devices[qtdDevices];

  public:
    /* criar um construtor  e passar a start para o produto talvez*/
    void addDevice(String _name, String _serial, String _host, String _post, String _erro, int _port);
    void handle(void);

};

#endif
