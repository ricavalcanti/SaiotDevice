#include "SaIoTDevice.h"

SaIoTDevice::SaIoTDevice(String _name, String _serial, String _email)
{
  name = _name;
  serial = _serial;
  email = _email;

};
/*SaIoTDevice::SaIoTDevice(String _name, String _serial){
  name = _name;
  serial = _serial;
}*/

SaIoTDevice::SaIoTDevice(){
};

void SaIoTDevice::preSetCom(WiFiClient& espClient, fptr _function){
  objCom.setClientw(espClient);
  objCom.setCallbackz(_function);
}
void SaIoTDevice::startDefault(String s){
  startCom(HOST, PORT, hostHttp, POSTDISPOSITIVO, s);
}
void SaIoTDevice::startCom(const char* hostSend, uint16_t portSend, const char* hostTok, const char* hostCd, String pUser){
  objCom.setServerPort(hostSend, portSend);
  wifi.autoConnect(serial.c_str());
  this->setToken(objCom.getToken(hostTok, email, pUser, serial));
  String keys[qtdControllers];
  for(unsigned int i=0; i<qtdControllers; i++){
    keys[i]+=controllers[i]->getKey();
  }
  objCom.registerDevice(serial, email, token, this->makeJconf(), hostCd, keys, qtdControllers);
}

void SaIoTDevice::setToken(String _token){
  token = _token;
}
void SaIoTDevice::setEmail(String _email){
  email = _email;
}
/*void SaIoTDevice::handle(void){
  for(int i=0;i<qtdSensors;i++){
    sensors[i]->verify();
  }
}*/
boolean SaIoTDevice::loopLoko(){
  return objCom.handleCom();
}
String SaIoTDevice::getName(void){
  return name;
}
String SaIoTDevice::getSerial(void){
  return serial;
}
String SaIoTDevice::getToken(void){
  return token;
}
String SaIoTDevice::getEmail(void){
  return email;
}
String SaIoTDevice::makeJconf(void){
  String JSON;
  JSON += "{\"token\":\""+token+"\",\"data\":{\"name\":\""+name +"\",\"serial\":\""+ serial+"\"";
  if(qtdControllers>0){
    JSON += ",\"controllers\":[";
    for(unsigned int i=0; i<qtdControllers; i++){
      JSON += controllers[i]->getJsonConfig();
      if(i==qtdControllers-1){
        JSON += "]";
      }else{
        JSON += ",";
      }
    }
  }
  if(qtdSensors>0){
    JSON += ",\"sensors\":[";
    for(unsigned int i=0; i<qtdSensors; i++){
      JSON += sensors[i]->getJsonConfig();
      if(i==qtdSensors-1){
        JSON += "]";
      }else{
        JSON += ",";
      }
    }
  }
  JSON +="}}";
  return JSON;
}

int SaIoTDevice::getNSensors(void){
  return qtdSensors;
}

int SaIoTDevice::getNControllers(void){
  return qtdControllers;
}

/*void SaIoTDevice::addSensor(SaIoTSensor &newSensor)
{
  sensors[qtdSensors++] = &newSensor;
}*/
/*void SaIoTDevice::addSensor(String _key, String _unit)
{
  sensors[qtdSensors++] = new SaIoTSensor(_key, _unit);
}*/
/*void SaIoTDevice::addSensor(String _key, int _deadbandMin, int _deadbandMax, int _timeout, int _resolution, bool _isAcumm, String _tag, String _unit)
{
  sensors[qtdSensors++] = new SaIoTSensor(_key, _deadbandMin, _deadbandMax, _timeout, _resolution, _isAcumm, _tag, _unit);
}*/

void SaIoTDevice::addController(SaIoTController &newController)
{
  controllers[qtdControllers++] = &newController;
}

/*void SaIoTDevice::addController(String _key, String _type)
{
  controllers[qtdControllers++] = new SaIoTController(_key, _type);
}
void SaIoTDevice::addController(String _key, String _type, String _tag, String _description, double _min, double _step, double _max)
{
  controllers[qtdControllers++] = new SaIoTController(_key, _type, _tag, _description, _min, _step, _max);
}*/
