#include "SaIoTController.h"

SaIoTController::SaIoTController() {}

SaIoTController::~SaIoTController() {}

SaIoTController::SaIoTController(String _key, String _type)
{
  setKey(_key);
  setType(_type);
}

SaIoTController::SaIoTController(String _key, String _type, String _tag)
{
  setKey(_key);
  setType(_type);
  setTag(_tag);
}

void SaIoTController::setKey(String _key)
{
  key = _key;
  // size_t size = _key.length();
  // for (size_t a=0; a<=64 && a<=size ;a++)
  //   {
  //     key[a] = char(_key[a]);
  //   }
}

String SaIoTController::getKey(void)
{
  return key;
}

void SaIoTController::setType(String _type)
{
  type = _type;
  // size_t size = _type.length();
  // for (size_t a=0; a<=64 && a<=size ;a++)
  //   {
  //     type[a] = char(_type[a]);
  //   }
}

String SaIoTController::getType(void)
{
  return type;
}

void SaIoTController::setTag(String _tag)
{
  tag = _tag;
  // size_t size = _label.length();
  // for (size_t a=0; a<=64 && a<=size ;a++)
  // {
  //   label[a] = char(_label[a]);
  // }
}

String SaIoTController::getTag(void)
{
  return tag;
}

/*void SaIoTController::setDescription(String _description)
{
  description = _description;
}

String SaIoTController::getDescription(void)
{
  return description;
}

void SaIoTController::setInterval(double _min, double _step, double _max)
{
  min = _min;
  step = _step;
  max = _max;
}

void SaIoTController::setMin(double _min)
{
  min = _min;
}
void SaIoTController::setMax(double _max)
{
  max = _max;
}

void SaIoTController::setStep(double _step)
{
  step = _step;
}

double SaIoTController::getMin(void)
{
  return min;
}

double SaIoTController::getMax(void)
{
  return max;
}

double SaIoTController::getStep(void)
{
  return step;
}*/
void SaIoTController::setJsonConfig(void){
  jConfExt += ("{\"key\":\"" + key + "\",\"type\":\"" + type + "\",\"tag\":\"" + tag + "\"}");
}

void SaIoTController::setJsonConfig(String _jConfExt){
  jConfExt = _jConfExt;
  //setKey(_jConfExt[key]);
}

/*void SaIoTController::setJsonConfig(String _jConfExt, String _complement){

}*/

String SaIoTController::getJsonConfig(void){
  return jConfExt;
}

void SaIoTController::setAction(func_pointer _function){
  function = _function;
}


