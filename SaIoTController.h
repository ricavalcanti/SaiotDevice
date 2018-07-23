#ifndef SaIoTController_h
#define SaIoTController_h

#include <Arduino.h>
#include<ArduinoJson.h>

typedef void (*func_pointer)(String); //necessario verif
class SaIoTController
{
private:
  String jConf;
  String key;

  //double min, max, step;
  func_pointer function;
  //void (*func_pointer)(int);


public:
  SaIoTController();
  SaIoTController(String _jsonConfig);
  SaIoTController(String _key, String _tClass);
  SaIoTController(String _key, String _tClass, String _tag);
  ~SaIoTController();

  String getKey(void);
  String getClass(void);
  String getTag(void);
  String getByField(String _field);

  void setJsonConfig(String _jConfExt); 
  String getJsonConfig(void); //pega todo o json de configuração pra ser enviado ao back

  void setAction(func_pointer _function);
};
#endif
