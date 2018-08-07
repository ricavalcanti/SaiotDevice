#include "SaIoTDeviceLib.h"

SaIoTDeviceLib::SaIoTDeviceLib(String _name, String _serial, String _email)
{
  name = _name;
  serial = _serial;
  email = _email;

};
SaIoTDeviceLib::SaIoTDeviceLib(){
};

void SaIoTDeviceLib::setToken(String _token){
  token = _token;
}

String SaIoTDeviceLib::getName(void){
  return name;
}
String SaIoTDeviceLib::getSerial(void){
  return serial;
}
String SaIoTDeviceLib::getToken(void){
  return token;
}
String SaIoTDeviceLib::getEmail(void){
  return email;
}
String SaIoTDeviceLib::makeJconf(void){
  //fazer json de config e retornar 
}



/*void SaIoTDeviceLib::addSensor(SaIoTSensor *newSensor)
{
  sensors[sensorIndex++] = newSensor;
}
void SaIoTDeviceLib::addSensor(String _key, String _unit)
{
  sensors[sensorIndex++] = new SaIoTSensor(_key, _unit);
}
void SaIoTDeviceLib::addSensor(String _key, int _deadbandMin, int _deadbandMax, int _timeout, int _resolution, bool _isAcumm, String _tag, String _unit)
{
  sensors[sensorIndex++] = new SaIoTSensor(_key, _deadbandMin, _deadbandMax, _timeout, _resolution, _isAcumm, _tag, _unit);
}*/

/*void SaIoTDeviceLib::addController(SaIoTController *newController)
{
  controllers[controllerIndex++] = newController;
}
void SaIoTDeviceLib::addController(String _key, String _type)
{
  controllers[controllerIndex++] = new SaIoTController(_key, _type);
}
void SaIoTDeviceLib::addController(String _key, String _type, String _tag, String _description, double _min, double _step, double _max)
{
  controllers[controllerIndex++] = new SaIoTController(_key, _type, _tag, _description, _min, _step, _max);
}*/

// void SaIoTDeviceLib::setUser(String user){
//   _usuario = user;
// }

// String SaIoTDeviceLib::getUser(void){
//   return _usuario;
// }

// void SaIoTDeviceLib::setUserPassword(String password){

// }

// String SaIoTDeviceLib::getUserPassword(void){
//   return _senhaUsuario;
// }
// void SaIoTDeviceLib::setProtocol(protocol protocolType){
//  _protocol = protocolType;
// }
//
// protocol SaIoTDeviceLib::getProtocol(void){
//  return _protocol;
// }

// String SaIoTDeviceLib::getSensors(void){
//  return sensor;
// }

// void SaIoTDeviceLib::setControler(String _controler){

// }

// String SaIoTDeviceLib::getControler(void){

// }
