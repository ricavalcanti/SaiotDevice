#ifndef InstantData_h
#define InstantData_h

#include <Arduino.h>
#include "DeviceData.h"

class InstantData : public DeviceData
{
private:
  double value;

public:
  void setValue(double _value);
  double getValue(void);
};
#endif
