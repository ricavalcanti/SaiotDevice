#include "SaIoTActuator.h"

  void SaIoTActuator::setKey(String _key){
    key = _key;
  }

  String SaIoTActuator::getKey(void){
    return key;
  }

  void SaIoTActuator::setType(String _type){
    type = _type;
  }

  String SaIoTActuator::getType(void){
    return type;
  }

  void SaIoTActuator::setLabel(String _label){
    label = _label;
  }

  String SaIoTActuator::getLabel(void){
    return label;
  }

  void SaIoTActuator::setInterval(int _min,int _step,int _max){
    min = _min;
    step = _step;
    max = _max;
  }

  void SaIoTActuator::setMin(int _min){
     min = _min;
  }
  void SaIoTActuator::setMax(int _max){
    max = _max;
  }

  void SaIoTActuator::setStep(int _step){
    step = _step;
  }

  int SaIoTActuator::getMin(void){
    return min;
  }

  int SaIoTActuator::getMax(void){
    return max;
  }

  int SaIoTActuator::getStep(void){
    return step;
  }