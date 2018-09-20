#include "SaIoTSensor.h"

SaIoTSensor::~SaIoTSensor() {}

SaIoTSensor::SaIoTSensor(String _jsonConfig){
    setJsonConfig(_jsonConfig);
}
SaIoTSensor::SaIoTSensor(String _key, String _tag, String _unit, String _type){
    jConf += ("{\"key\":\"" + _key + "\",\"unit\":\"" + _unit + "\",\"type\":\"" + _type + "\",\"tag\":\"" + _tag + "\"}");
    key = _key;
}
String SaIoTSensor::getJsonConfig(void){
    return jConf;
}
String SaIoTSensor::getKey(void){
    return key;
}
String SaIoTSensor::getSerial(void){
    return serial;
}
double SaIoTSensor::getValue(void){
    return value;
}
bool SaIoTSensor::getReport(){
    if(reportMe == 1){
        reportMe = 0;
        return 1;
    }else{
        return reportMe;
    }  
}
String SaIoTSensor::getByField(String _field){
    int idxField = jConf.indexOf(_field); 
	int init, end;
	
	if(idxField != -1){
	    init = jConf.indexOf(":", idxField) + 1; 
    if(jConf[init] == '\"'){
        init = init+1;
        end = jConf.indexOf("\"", init);
    }else{
        end = jConf.indexOf(",", init);
      if(end == -1){
		end = jConf.indexOf("}", init);
        }
	}
        return jConf.substring(init,end); 
    }else{
		return "-1";
	}
}

String SaIoTSensor::getUnit(void){
    return getByField("unit");
}
String SaIoTSensor::getTag(void){
    return getByField("tag");
}
String SaIoTSensor::getType(void){
    return getByField("type");
}
String SaIoTSensor::getLastDate(void){
    return lastDate;
}

//METODOS SET 

void SaIoTSensor::setJsonConfig(String _jsonConfig){
    jConf = _jsonConfig;
    key = getByField("key");
    serial = getByField("serial");
}

void SaIoTSensor::sendData(double _value){
    reportMe = 1;
    return this->sendData(_value,SaIoTCom::getDateNow());
}

void SaIoTSensor::sendData(double _value, String dateTime){
    reportMe = 1;
    value = _value;
    lastDate = dateTime;
}
