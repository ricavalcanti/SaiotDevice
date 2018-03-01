#include<SaIoTSensor.h>


void SaIoTSensor::setKey(String _key){
    key = _key;
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
    label = _label;
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
    unit = _unit;
}

String SaIoTSensor::getUnit(void){
    return unit;
}