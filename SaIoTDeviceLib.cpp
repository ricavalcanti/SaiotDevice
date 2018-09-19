#include "SaIoTDeviceLib.h"

<<<<<<< HEAD

SaIoTDeviceLib::SaIoTDeviceLib(){
};
=======
>>>>>>> c0cf819367c016b5ddc9ff9f374d8759ae4b8d1a
SaIoTDeviceLib::SaIoTDeviceLib(String _name, String _serial, String _email)
{
  name = _name;
  serial = _serial;
  email = _email;

};
<<<<<<< HEAD
void SaIoTDeviceLib::preSetCom(WiFiClient& espClient, fptr _function){
  objCom.setClient(espClient);
  objCom.setCallback(_function);
  //fptr = *SaIoTDeviceLib::callback(char* topic, byte* payload, unsigned int length);
  //objCom.setCallback(&SaIoTDeviceLib::callback(char* topic, byte* payload, unsigned int length));
};
void SaIoTDeviceLib::startDefault(String s){
  startCom(HOST, PORT, hostHttp, POSTDISPOSITIVO, s);
};
void SaIoTDeviceLib::startCom(const char* hostSend, uint16_t portSend, const char* hostTok, const char* hostCd, String pUser){
  objCom.setServerPort(hostSend, portSend);
  //wm
  wifi.autoConnect(serial.c_str());
  this->setToken(objCom.getToken(hostTok, email, pUser, serial));
  //fim wm
  String keys[qtdControllers];
  for(int i=0; i<qtdControllers; i++){
    keys[i]+=controllers[i]->getKey();
  }
  objCom.registerDevice(serial, email, token, this->getJconf(), hostCd, keys, qtdControllers);
};
void SaIoTDeviceLib::setToken(String _token){
  token = _token;
};
void SaIoTDeviceLib::setEmail(String _email){
  email = _email;
};

boolean SaIoTDeviceLib::handleLoop(){
  for(int i=0;i<qtdSensors;i++){
    if(sensors[i]->getReport()){
      String payload =""; //VER COMO FICARIA PRA TRATAR A DATA
      payload += "{\"token\":\""+token+"\",\"data\":{\"serial\":\""+serial+"\",\"key\":\""+sensors[i]->getKey()+"\",\"value\":" +sensors[i]->getValue()+",\"dateTime\":\""+sensors[i]->getLastDate()+"\"}}";
      if(objCom.publishData(payload)){
        Serial.println("Dado enviado!");
      }else{
        Serial.print("Erro ao enviar o dado: ");
        Serial.println(payload);
      }
    }
  }
=======
/*SaIoTDeviceLib::SaIoTDeviceLib(String _name, String _serial){
  name = _name;
  serial = _serial;
}*/

SaIoTDeviceLib::SaIoTDeviceLib(){
};

void SaIoTDeviceLib::preSetCom(WiFiClient& espClient, fptr _function){
  objCom.setClientw(espClient);
  objCom.setCallbackz(_function);
}
void SaIoTDeviceLib::startDefault(String s){
  startCom(HOST, PORT, hostHttp, POSTDISPOSITIVO, s);
}
void SaIoTDeviceLib::startCom(const char* hostSend, uint16_t portSend, const char* hostTok, const char* hostCd, String pUser){
  objCom.setServerPort(hostSend, portSend);
  wifi.autoConnect(serial.c_str());
  this->setToken(objCom.getToken(hostTok, email, pUser, serial));
  String keys[qtdControllers];
  for(unsigned int i=0; i<qtdControllers; i++){
    keys[i]+=controllers[i]->getKey();
  }
  objCom.registerDevice(serial, email, token, this->makeJconf(), hostCd, keys, qtdControllers);
}

void SaIoTDeviceLib::setToken(String _token){
  token = _token;
}
void SaIoTDeviceLib::setEmail(String _email){
  email = _email;
}
/*void SaIoTDeviceLib::handle(void){
  for(int i=0;i<qtdSensors;i++){
    sensors[i]->verify();
  }
}*/
boolean SaIoTDeviceLib::handleLoop(){
>>>>>>> c0cf819367c016b5ddc9ff9f374d8759ae4b8d1a
  return objCom.handleCom();
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
<<<<<<< HEAD
String SaIoTDeviceLib::getJconf(void){
=======
String SaIoTDeviceLib::makeJconf(void){
>>>>>>> c0cf819367c016b5ddc9ff9f374d8759ae4b8d1a
  String JSON;
  JSON += "{\"token\":\""+token+"\",\"data\":{\"name\":\""+name +"\",\"serial\":\""+ serial+"\"";
  if(qtdControllers>0){
    JSON += ",\"controllers\":[";
<<<<<<< HEAD
    for(int i=0; i<qtdControllers; i++){
=======
    for(unsigned int i=0; i<qtdControllers; i++){
>>>>>>> c0cf819367c016b5ddc9ff9f374d8759ae4b8d1a
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
<<<<<<< HEAD
    for(int i=0; i<qtdSensors; i++){
=======
    for(unsigned int i=0; i<qtdSensors; i++){
>>>>>>> c0cf819367c016b5ddc9ff9f374d8759ae4b8d1a
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

int SaIoTDeviceLib::getNSensors(void){
  return qtdSensors;
}

int SaIoTDeviceLib::getNControllers(void){
  return qtdControllers;
}

<<<<<<< HEAD
void SaIoTDeviceLib::addSensor(SaIoTSensor &newSensor)
{
  sensors[qtdSensors++] = &newSensor;
}
=======
/*void SaIoTDeviceLib::addSensor(SaIoTSensor &newSensor)
{
  sensors[qtdSensors++] = &newSensor;
}*/
>>>>>>> c0cf819367c016b5ddc9ff9f374d8759ae4b8d1a
/*void SaIoTDeviceLib::addSensor(String _key, String _unit)
{
  sensors[qtdSensors++] = new SaIoTSensor(_key, _unit);
}*/
/*void SaIoTDeviceLib::addSensor(String _key, int _deadbandMin, int _deadbandMax, int _timeout, int _resolution, bool _isAcumm, String _tag, String _unit)
{
  sensors[qtdSensors++] = new SaIoTSensor(_key, _deadbandMin, _deadbandMax, _timeout, _resolution, _isAcumm, _tag, _unit);
}*/

void SaIoTDeviceLib::addController(SaIoTController &newController)
{
  controllers[qtdControllers++] = &newController;
}

/*void SaIoTDeviceLib::addController(String _key, String _type)
{
  controllers[qtdControllers++] = new SaIoTController(_key, _type);
}
void SaIoTDeviceLib::addController(String _key, String _type, String _tag, String _description, double _min, double _step, double _max)
{
  controllers[qtdControllers++] = new SaIoTController(_key, _type, _tag, _description, _min, _step, _max);
}*/




