#include <Arduino.h>
#include "InstantData.h"

void InstantData::setValue(double _value)
{
  value = _value;
}

double InstantData::getValue(void)
{
  return value;
}
