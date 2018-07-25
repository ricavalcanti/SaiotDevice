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
double SaIoTSensor::getValor(void){
    return valor;
}
String SaIoTSensor::getByField(String _field){
    int idxField = jConf.indexOf(_field); //field
	int init, end;
	
	if(idxField != -1){
		init = jConf.indexOf(":", idxField) + 2; 
		end = jConf.indexOf("\"", init);
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
void SaIoTSensor::setValor(double _valor){
    valor = _valor;
}

void verify(void){

}





// METODOS ANTIGOS //


/*SaIoTSensor::SaIoTSensor(String _key, int _deadbandMin, int _deadbandMax, int _timeout, int _resolution, bool _isAcumm, String _tag, String _unit)
{
    setKey(_key);
    // setSyncCommunication(_isSync);
    setDeadBandMin(_deadbandMin);
    setDeadBandMax(_deadbandMax);
    setTimeout(_timeout);
    setResolution(_resolution);
    // setDigitalDevice(_isDigital);
    setAcummulate(_isAcumm);
    setTag(_tag);
    // setValor(_valor);
    setUnit(_unit);
}

SaIoTSensor::SaIoTSensor(String _key, String _unit)
{
    setKey(_key);
    setUnit(_unit);
}
void SaIoTSensor::setKey(String _key)
{
    size_t size = _key.length();
    for (size_t a = 0; a <= 64 && a <= size; a++)
    {
        key[a] = char(_key[a]);
    }
}

String SaIoTSensor::getKey(void)
{
    return key;
}*/

// void SaIoTSensor::setSyncCommunication(bool _isSync){
//     isSync = _isSync;
// }

// bool SaIoTSensor::isSyncCommunication(void){
//     return isSync;
// }

/*void SaIoTSensor::setDeadBandMin(int _deadbandMin)
{
    deadbandMin = _deadbandMin;
}

int SaIoTSensor::getDeadBandMin(void)
{
    return deadbandMin;
}
void SaIoTSensor::setDeadBandMax(int _deadbandMax)
{
    deadbandMax = _deadbandMax;
}

int SaIoTSensor::getDeadBandMax(void)
{
    return deadbandMax;
}

void SaIoTSensor::setTimeout(int _timeout)
{
    timeout = _timeout;
}

int SaIoTSensor::getTimeout(void)
{
    return timeout;
}
*/
// void SaIoTSensor::setDigitalDevice(bool _isDigital){
//     isDigital = _isDigital;
// }

// bool SaIoTSensor::isDigitalDevice(void){
//     return isDigital;
// }

/*void SaIoTSensor::setAcummulate(bool _isAcummulate)
{
    isAcumm = _isAcummulate;
}

bool SaIoTSensor::isAcummulate(void)
{
    return isAcumm;
}

void SaIoTSensor::setTag(String _keytag)
{
    size_t size = _keytag.length();
    for (size_t a = 0; a <= 64 && a <= size; a++)
    {
        tag[a] = char(_keytag[a]);
    }
}

String SaIoTSensor::getTag(void)
{
    return tag;
}

void SaIoTSensor::setValor(double _valor)
{
    valor = _valor;
}

double SaIoTSensor::getValor(void)
{
    return valor;
}

void SaIoTSensor::setUnit(String _unit)
{
    size_t size = _unit.length();
    for (size_t a = 0; a <= 64 && a <= size; a++)
    {
        unit[a] = char(_unit[a]);
    }
}

String SaIoTSensor::getUnit(void)
{
    return unit;
}

void SaIoTSensor::setResolution(unsigned long _resolution)
{
    resolution = _resolution;
}
unsigned long SaIoTSensor::getResolution(void)
{
    return resolution;
}
void SaIoTSensor::verify(void)
{
    if (timeout)
    {
        if ((abs(millis() - lastTimeout) > timeout))
        {
            // send();
            // atualiza a variável lastTimeout para o time da última ocorrência do timeout 
            lastTimeout = millis();
        }
    }
}
*/
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
