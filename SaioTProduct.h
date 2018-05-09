#ifndef SaioTProduct_h
#define SaioTProduct_h

#include <Arduino.h>

#ifndef qtdDevices
#define qtdDevices 1
#endif

#include "SaiotDeviceLib.h"

class SaIoTProduct
{
private:
  unsigned int deviceIndex = 0;
  SaIoTDeviceLib *devices[qtdDevices];

public:
  /* criar um construtor  e passar a start para o produto talvez*/
  void addDevice(String _name, String _serial, String _host, String _post, String _erro, int _port);
  void addDevice(SaIoTDeviceLib *newDevice);
  void handle(void);
};

#endif
