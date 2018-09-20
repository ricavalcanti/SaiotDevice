#ifndef SaIoTSensor_h
#define SaIoTSensor_h

#include <Arduino.h>
#include "SaIoTCom.h"

#define NULL_VALUE -1
class SaIoTSensor
{
private:

  String jConf;
  String key;
  String serial;
  String lastDate;
  bool reportMe = 0;
  double value;
public:
  SaIoTSensor();
  SaIoTSensor(String _jsonConfig);
  SaIoTSensor(String _key, String _tag, String _unit, String _type); //campos obrigatorios p o server
  ~SaIoTSensor();

  String getKey(void); //1
  String getSerial(void); //2
  //1 e 2: campos necessários sempre que for enviar dados ao server 

  String getByField(String _field); 
  String getUnit(void);
  String getType(void);
  String getTag(void);
  String getJsonConfig(void);
  String getLastDate(void);
  double getValue(void);
  bool getReport();

  void setJsonConfig(String _jConf);
  void sendData(double _value, String dateTime);

};
#endif
