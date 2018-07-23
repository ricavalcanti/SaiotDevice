#ifndef SaIoTSensor_h
#define SaIoTSensor_h

#include <Arduino.h>

class SaIoTSensor
{
private:
  /*String key;
  String tag;
  String unit;
  String type;
  boolean accumulate;*/

  String jConf;
  String key;
  String serial;
  //Pensar em atributos que vão fora do json de configuração! 
  
  /* timeout 3 segundos = 3 * 1000 milissegundos */
  unsigned long int deadband = 0,
                    timeout = 3000,
                    lastTimeout = 0,
                    lastResolution = 0,
                    resolution = 0;
  double valor;
  
  //bool isAcumm = true , isSync = true, isDigital=true;
  // typedef void (*verifyfunct)(void);
public:
  SaIoTSensor();
  SaIoTSensor(String _jsonConfig);
  SaIoTSensor(String _key, String _tag, String _unit, String _type); //campos obrigatorios p o server
  ~SaIoTSensor();

  /*****************************************************************************************************************************************************
         * Sensor JSON Functions
        ******************************************************************************************************************************************************/

  String getKey(void); //1
  String getSerial(void); //2
  //1 e 2: campos necessários p enviar dados ao server 

  String getByField(String _field); 
  String getUnit(void);
  String getType(void);
  String getTag(void);
  String getJsonConfig(void);

  void setJsonConfig(String _jConf);
  void setValor(double _valor);
  double getValor(void);

  void verify(void);

  
  
  
  
  
  
  
  /*
  SaIoTSensor();
  SaIoTSensor(String _key, int _deadbandMin, int _deadbandMax, int _timeout, int _resolution, bool _isAcumm, String _tag, String _unit);
  SaIoTSensor(String _key, String _unit);
  ~SaIoTSensor();*/

  /*****************************************************************************************************************************************************
         * Sensor JSON Functions
        ******************************************************************************************************************************************************/
  /*void setKey(String _key);
  String getKey(void);

  void setSyncCommunication(bool _isSync);
  bool isSyncCommunication(void);

  void setDeadBandMin(int _deadbandMin);
  int getDeadBandMin(void);
  void setDeadBandMax(int _deadbandMax);
  int getDeadBandMax(void);

  void setTimeout(int _timeout);
  int getTimeout(void);*/

  // void setDigitalDevice(bool _isDigital);
  // bool isDigitalDevice(void);

  /*void setAcummulate(bool _isAcummulate);
  bool isAcummulate(void);

  void setTag(String _keytag);
  String getTag(void);

  void setValor(double _valor);
  double getValor(void);

  void setUnit(String _unit);
  String getUnit(void);

  void setResolution(unsigned long _resolution);
  unsigned long getResolution(void);*/

  /****************************************************************
   * Sensor Reading Functions: Verification and interruptions
  ****************************************************************/
  //void verify(void);

  /* envia ao servidor o json com as informações da leitura do sensor*/
  /*deve pertencer ao device que decide se está na hora de enviar ou não*/
  //int send(void);
};

#endif
