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
String SaIoTSensor::getByField(String _field){
    int idxField = jConf.indexOf(_field); //field
	int init, end;
	
	if(idxField != -1){
		init = jConf.indexOf(":", idxField) + 1; 
		end = jConf.indexOf(",", init);
		if(end == -1){
			end = jConf.indexOf("}", init);
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

//METODOS SET 

void SaIoTSensor::setJsonConfig(String _jsonConfig){
    jConf = _jsonConfig;
    key = getByField("key");
    serial = getByField("serial");
}
void SaIoTSensor::setValue(double _value){
    value = _value;
}

void SaIoTSensor::verify(void){
    if(deadband != NULL_VALUE){
        if(exceededDeadband(deadband)){
            sendValue()
        }
    }
    if(timeout != NULL_VALUE){
        if(exceededTimeout(timeout)){
            sendValue()
        }
    }
    if(resolution != NULL_VALUE){
        if(exceededResolution(resolution)){
            sendValue()
        }
    }
}

bool SaIoTSensor::exceededDeadband(unsigned long int deadband){
    (value>deadband)? return true : return false;
}
bool SaIoTSensor::exceededTimeout(unsigned long int timeout){
    unsigned long int currentTime = millis();
    ((currentTime - lastTimeout) > timeout )? return true : return false;
}
bool SaIoTSensor::exceededResolution(resolution){
 //pensar em como mensurar
}

int SaIoTSensor::sendValue(void){
    lastTimeout = millis();
    //enviar
}