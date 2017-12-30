# Biblioteca SAIOTDevice

Biblioteca para uso geral em dispositivos desenvolvidos pelo SAIOT

##Contem:

- Gerenciamento de *wifi* (WiFiManager);
- Gerenciamento de JSONs (ArduinoJson);
- Diferentes protocolos:
  - Websocket (SocketIOClient);
  - MQTT (pubsubclient) **ver Limitações**;
  - HTTP **ver Limitações**;
- Gerenciamento de dados dos dispositivos de acordo com o tipo, sendo esses:
  - Dispositivos que necessitam acumular dados coletados;
  - Dispositivos que precisam somente coletar dados momentâneos;
  - Dispositivos acumuladores que necessitam de controle de intensidade;

##Como Usar:
###Incluindo no projeto

1. Para usar basta, primeiramente, fazer o *download* do código, extrair e colar na pasta de bibliotecas do seu projeto;

2. Em seguide, deve-se incluí-la em seu projeto e criar um objeto conforme exemplificado abaixo;

```c++
include "SAIOTDevice.h"

SAIOTDevice newDevice;
```
###Configurando
Uma vez incluida no projeto, a biblioteca facilitará várias etapas do seu projeto. Aproveitando o objeto exemplo criado no ítem anterior temos os seguintes comandos para:

#### Iniciar o Wifi
```c++
newDevice.startWifi();
```
Caso seja a primeira conexão, o dispositivo entrará no modo AP. Para conectar, basta então, acessar a rede gerada pelo microcontrolador e configurá-la. No mais, o dispositivo tentará se reconectar com a rede salva anteriormente.


##Limitações e futuras melhorias:

- Protocolo HTTP ainda não implementado;
- Protocolo MQTT parcialmente implementado;
- Protocolo WebSocket implementado utilizando-se da biblioteca "SocketIOClient", pretende-se modificar para a "arduinoWebSockets" em breve;