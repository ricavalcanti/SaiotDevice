#include "SaIoTController.h"

SaIoTController::SaIoTController() {}

SaIoTController::~SaIoTController() {
}

SaIoTController::SaIoTController(String _jsonConfig){
  setJsonConfig(_jsonConfig);
}

SaIoTController::SaIoTController(String _key, String _tClass) //esse método é necessário?
{
  jConf = ("{\"key\":\"" + _key + "\",\"class\":\"" + _tClass + "\"}");
  key = _key;
}

SaIoTController::SaIoTController(String _key, String _tClass, String _tag)
{
  jConf += ("{\"key\":\"" + _key + "\",\"class\":\"" + _tClass + "\",\"tag\":\"" + _tag + "\"}");
  key = _key;
}

String SaIoTController::getKey(void)
{
  return getByField("key");
}

String SaIoTController::getClass(void)
{
  return getByField("class");
}

String SaIoTController::getTag(void)
{
  return getByField("tag");
}

String SaIoTController::getByField(String _field){
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

void SaIoTController::setJsonConfig(String _jConf){
  jConf = _jConf;
  key = getByField("key");

}

String SaIoTController::getJsonConfig(void){
  return jConf;
}

void SaIoTController::setAction(func_pointer _function){
  function = _function;
}


