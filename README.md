# SaIoTDevicelib
Biblioteca genérica para gerenciamento de dispositivos IoT

## Contém:
- Gerenciamento de *WiFi* (WiFiManager);
- Gerenciamento de JSONs (ArduinoJson);

## Como usar:
### Incluindo  no projeto
1. Para usar basta, primeiramente, fazer o *download* do código, extrair e colar na pasta de bibliotecas do seu projeto;
2. Em seguida, deve-se incluí-la em seu projeto e criar um objeto conforme exemplificado abaixo;
  ```c++
 #include  <SaIoTDeviceLib.h>
SaIoTDeviceLib myDevice;
```
### Configurando
Uma vez incluída, a biblioteca facilitará várias etapas do seu projeto. Aproveitando o objeto exemplo criado no item anterior temos os seguintes comandos para:

#### Iniciar conexão com a internet e com o servidor

```c++
mydevice.start(SERIAL,HOST,PORT,POST)
`````
sendo
- **Serial** *char**: 
- **Host** *char**:
- **Port** *int*:  Porta de comunicação
- **Post** *char**: Nome do evento 

**OBS.:** Caso seja a primeira conexão, o dispositivo entrará no modo AP. Para conectar, basta então, acessar a rede gerada pelo microcontrolador e configurá-la. No mais, o dispositivo tentará se reconectar com a rede salva anteriormente.
