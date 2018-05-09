#ifndef SaIoTController_h
#define SaIoTController_h

#include <Arduino.h>

class SaIoTController
{
private:
  String key;
  String type;
  String tag;
  String description;

  double min, max, step;

public:
  SaIoTController(String _key, String _type);
  SaIoTController(String _key, String _type, String _tag, String _description, double _min, double _step, double _max);
  ~SaIoTController();

  void setKey(String _key);
  String getKey(void);

  void setType(String _type);
  String getType(void);

  void setTag(String _tag);
  String getTag(void);

  void setDescription(String _description);
  String getDescription(void);

  void setInterval(double _min, double _step, double _max);

  void setMin(double _min);
  double getMin(void);

  void setMax(double _max);
  double getMax(void);

  void setStep(double _step);
  double getStep(void);
};
#endif
