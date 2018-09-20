#include "SaIoTDeviceLib.h"


SaIoTDeviceLib::SaIoTDeviceLib(){
};
SaIoTDeviceLib::SaIoTDeviceLib(String _name, String _serial, String _email)
{
  name = _name;
  serial = _serial;
  email = _email;

};
void SaIoTDeviceLib::preSetCom(WiFiClient& espClient, fptr _function){
  objCom.setClient(espClient);
  objCom.setCallback(_function);

};
void SaIoTDeviceLib::startDefault(String s){
  startCom(HOST, PORT, hostHttp, POSTDISPOSITIVO, s);
};
void SaIoTDeviceLib::startCom(const char* hostSend, uint16_t portSend, const char* hostTok, const char* hostCd, String pUser){
  objCom.setServerPort(hostSend, portSend);
  //wm
  WiFiManager wifi;
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
      String payload ="";
      payload += "{\"token\":\""+token+"\",\"data\":{\"serial\":\""+serial+"\",\"key\":\""+sensors[i]->getKey()+"\",\"value\":" +sensors[i]->getValue()+",\"dateTime\":\""+sensors[i]->getLastDate()+"\"}}";
      if(objCom.publishData(payload)){
        Serial.println("Dado enviado!");
      }else{
        Serial.print("Erro ao enviar o dado: ");
        Serial.println(payload);
      }
    }
  }
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
String SaIoTDeviceLib::getJconf(void){
  String JSON;
  JSON += "{\"token\":\""+token+"\",\"data\":{\"name\":\""+name +"\",\"serial\":\""+ serial+"\"";
  if(qtdControllers>0){
    JSON += ",\"controllers\":[";
    for(int i=0; i<qtdControllers; i++){
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
    for(int i=0; i<qtdSensors; i++){
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

void SaIoTDeviceLib::addSensor(SaIoTSensor &newSensor)
{
  sensors[qtdSensors++] = &newSensor;
}

void SaIoTDeviceLib::addController(SaIoTController &newController)
{
  controllers[qtdControllers++] = &newController;
}




