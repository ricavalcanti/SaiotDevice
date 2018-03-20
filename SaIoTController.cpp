#include "SaIoTController.h"

  void SaIoTController::setKey(String _key){
  size_t size = _key.length();
  for (size_t a=0; a<=64 && a<=size ;a++)
    {
      key[a] = char(_key[a]);
    }
  }

  String SaIoTController::getKey(void){
    return key;
  }

  void SaIoTController::setType(String _type){
  	size_t size = _type.length();
  	for (size_t a=0; a<=64 && a<=size ;a++)
      {
        type[a] = char(_type[a]);
      }
  }

  String SaIoTController::getType(void){
    return type;
  }

void SaIoTController::setLabel(String _label){
  size_t size = _label.length();
  for (register size_t a=0; a<=64 && a<=size ;a++)
  {
    label[a] = char(_label[a]);
  }
  }

  String SaIoTController::getLabel(void){
    return label;
  }

  void SaIoTController::setInterval(double _min,double _step,double _max){
    min  = _min;
    step = _step;
    max  = _max;
  }

  void SaIoTController::setMin(double _min){
     min = _min;
  }
  void SaIoTController::setMax(double _max){
    max = _max;
  }

  void SaIoTController::setStep(double _step){
    step = _step;
  }

  double SaIoTController::getMin(void){
    return min;
  }

  double SaIoTController::getMax(void){
    return max;
  }

  double SaIoTController::getStep(void){
    return step;
  }
