#include"SaIoTSensor.h"

SaIoTSensor::SaIoTSensor(String _key, bool _isSync, int _deadband, int _timeout, bool _isDigital, bool _isAcumm, String _label, double _valor, String _unit, int _resolution){
    setKey(_key);
    setSyncCommunication(_isSync);
    setDeadBand(_deadband);
    setTimeout(_timeout);
    setDigitalDevice(_isDigital);
    setAcummulate(_isAcumm);
    setLabel(_label);
    setValor(_valor);
    setUnit(_unit);
    setResolution(_resolution);
}

void SaIoTSensor::setKey(String _key){
  size_t size = _key.length();
  for (size_t a=0; a<=64 && a<=size ;a++)
          {
            key[a] = char(_key[a]);
          }
}

String SaIoTSensor::getKey(void){
    return key;
}

void SaIoTSensor::setSyncCommunication(bool _isSync){
    isSync = _isSync;
}

bool SaIoTSensor::isSyncCommunication(void){
    return isSync;
}

void SaIoTSensor::setDeadBand(int _deadband){
    deadband = _deadband;
}

int SaIoTSensor::getDeadBand(void){
    return deadband;
}

void SaIoTSensor::setTimeout(int _timeout){
    timeout = _timeout;
}

int SaIoTSensor::getTimeout(void){
    return timeout;
}

void SaIoTSensor::setDigitalDevice(bool _isDigital){
    isDigital = _isDigital;
}

bool SaIoTSensor::isDigitalDevice(void){
    return isDigital;
}

void SaIoTSensor::setAcummulate(bool _isAcummulate){
    isAcumm = _isAcummulate;
}

bool SaIoTSensor::isAcummulate(void){
    return isAcumm;
}

void SaIoTSensor::setLabel(String _label){
  size_t size = _label.length();
  for (size_t a=0; a<=64 && a<=size ;a++)
          {
            label[a] = char(_label[a]);
          }
}

String SaIoTSensor::getLabel(void){
    return label;
}

void SaIoTSensor::setValor(double _valor){
    valor = _valor;
}

double SaIoTSensor::getValor(void){
    return valor;
}

void SaIoTSensor::setUnit(String _unit){
  size_t size = _unit.length();
  for (size_t a=0; a<=64 && a<=size ;a++)
          {
            unit[a] = char(_unit[a]);
          }
}

String SaIoTSensor::getUnit(void){
    return unit;
}

void SaIoTSensor::setResolution(unsigned long _resolution){
    resolution = _resolution;
}
unsigned long SaIoTSensor::getResolution(void){
    return resolution;
}
void SaIoTSensor::verify(void){
    if(timeout){
        if((abs(millis()-lastTimeout)> timeout)){
            send();
            /*atualiza a variável lastTimeout para o time da última ocorrência do timeout*/
            lastTimeout = millis();
        }
    }
}
//
// /* envia ao servidor o json com as informações da leitura do sensor*/
// int SaIoTSensor::send(void){
//     switch(_protocol){
// 		case WS:
// 			wsClient->emit(value,key);
// 			break;
// 		case HTTP:
//             Serial.println(F("[SaIoT] HTTP loop - not setted"));
// 		case MQTT:
//             Serial.println(F("[SaIoT] MQTT loop - not setted"));
// 	}
// }
