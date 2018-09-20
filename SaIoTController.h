#ifndef SaIoTController_h
#define SaIoTController_h

#include <Arduino.h>

class SaIoTController
{
private:
  String jConf;
  String key;
public:
  SaIoTController();
  SaIoTController(String _jsonConfig);
  SaIoTController(String _key, String _tag, String _tClass); //campos obrigatorios p/ o server
  ~SaIoTController();

  String getKey(void); 
  String getClass(void);
  String getTag(void);
  String getByField(String _field);
  
  void setJsonConfig(String _jConfExt); 
  String getJsonConfig(void);

};
#endif
