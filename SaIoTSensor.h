#ifndef SaIoTSensor_h
#define SaIoTSensor_h

#include <Arduino.h>

#define NULL_VALUE -1

class SaIoTSensor
{
private:
  /*String key;
  String tag;
  String unit;
  String type;
  boolean accumulate;*/

  String jConf;
  String key;
  String serial;
  //Pensar em atributos que vão fora do json de configuração! 
  
  /* timeout 3 segundos = 3 * 1000 milissegundos */
  long int deadband = NULL_VALUE,
                    timeout = NULL_VALUE,
                    lastTimeout = 0,
                    lastResolution = 0,
                    resolution = NULL_VALUE;
  double value;
  
  //bool isAcumm = true , isSync = true, isDigital=true;
  // typedef void (*verifyfunct)(void);
public:
  SaIoTSensor();
  SaIoTSensor(String _jsonConfig);
  SaIoTSensor(String _key, String _tag, String _unit, String _type); //campos obrigatorios p o server
  ~SaIoTSensor();

  /*****************************************************************************************************************************************************
     Sensor JSON Functions
  ******************************************************************************************************************************************************/

  String getKey(void); //1
  String getSerial(void); //2
  //1 e 2: campos necessários p enviar dados ao server 

  String getByField(String _field); 
  String getUnit(void);
  String getType(void);
  String getTag(void);
  String getJsonConfig(void);
  double getValue(void);

  void setJsonConfig(String _jConf);
  void setValue(double _value);
  void setTimeout(long int _timeout);
  void setDeadBand(long int _deadband);

  /****************************************************************
   * Sensor Reading Functions: Verification and interruptions
  ****************************************************************/

  void verify(void);
  bool exceededDeadband(long int deadband);
  bool exceededTimeout(long int timeout);
  bool exceededResolution(long int resolution);

   /****************************************************************
   * Sensor Communication Functions: sending data
  ****************************************************************/
  int sendValue(void);
};

#endif
