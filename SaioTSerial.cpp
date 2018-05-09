#include "SaIoTProduct.h"

void SaIoTProduct::addDevice(String _name, String _serial, String _host, String _post, String _erro, int _port)
{
  devices[deviceIndex++] = new SaIoTDeviceLib(_name, _serial, _host, _post, _erro, _port);
};

void SaIoTProduct::addDevice(SaIoTDeviceLib *newDevice)
{
  devices[deviceIndex++] = newDevice;
};

void SaIoTProduct::handle(void){
    //Protocolo é atributo do DEVICE, pensar em como fazer o handle -> verify p/ cada sensor e/ou controller
    // switch(_protocol){
    // case WS:
    //ws->monitor();
    // break;

    //   case HTTP: Serial.println(F("[SaIoT] HTTP loop - not setted"));
    //   case MQTT: Serial.println(F("[SaIoT] MQTT loop - not setted"));
    // }
};
