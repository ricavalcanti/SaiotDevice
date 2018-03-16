#include "SaIoTActuator.h"

  void SaIoTActuator::setKey(String _key){
  size_t size = _key.length();
  for (size_t a=0; a<=64 && a<=size ;a++)
    {
      key[a] = char(_key[a]);
    }
  }

  String SaIoTActuator::getKey(void){
    return key;
  }

  void SaIoTActuator::setType(String _type){
  	size_t size = _type.length();
  	for (size_t a=0; a<=64 && a<=size ;a++)
      {
        type[a] = char(_type[a]);
      }
  }

  String SaIoTActuator::getType(void){
    return type;
  }

void SaIoTActuator::setLabel(String _label){
  size_t size = _label.length();
  for (register size_t a=0; a<=64 && a<=size ;a++)
  {
    label[a] = char(_label[a]);
  }
  }

  String SaIoTActuator::getLabel(void){
    return label;
  }

  void SaIoTActuator::setInterval(double _min,double _step,double _max){
    min  = _min;
    step = _step;
    max  = _max;
  }

  void SaIoTActuator::setMin(double _min){
     min = _min;
  }
  void SaIoTActuator::setMax(double _max){
    max = _max;
  }

  void SaIoTActuator::setStep(double _step){
    step = _step;
  }

  double SaIoTActuator::getMin(void){
    return min;
  }

  double SaIoTActuator::getMax(void){
    return max;
  }

  double SaIoTActuator::getStep(void){
    return step;
  }
