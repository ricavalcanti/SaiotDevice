# Biblioteca SaiotDevice

Biblioteca para uso geral em dispositivos desenvolvidos pelo SAIOT

## Contém:

- Gerenciamento de *wifi* (WiFiManager);
- Gerenciamento de JSONs (ArduinoJson);
- Diferentes protocolos:
  - Websocket (SocketIOClient);
  - MQTT (pubsubclient) ([**ver Limitações**](https://github.com/daniellycosta/SAIOTDevice#limitações-e-futuras-melhorias));
  - HTTP ([**ver Limitações**](https://github.com/daniellycosta/SAIOTDevice#limitações-e-futuras-melhorias));
- Gerenciamento de dados dos dispositivos de acordo com o tipo, sendo esses:
  - Dispositivos que necessitam acumular dados coletados (acumuladores);
  - Dispositivos que precisam somente coletar dados momentâneos (intantâneos), sendo esses divididos ainda em:
    - Que necessitam de controle de intensidade;
    - Que não necessitam de controle de intensidade;

## Como Usar:
### Incluindo no projeto

1. Para usar basta, primeiramente, fazer o *download* do código, extrair e colar na pasta de bibliotecas do seu projeto;

2. Em seguide, deve-se incluí-la em seu projeto e criar um objeto conforme exemplificado abaixo;

```c++
include "SaiotDevice.h"

SaiotDevice newDevice;
```
### Configurando
Uma vez incluida, a biblioteca facilitará várias etapas do seu projeto. Aproveitando o objeto exemplo criado no ítem anterior temos os seguintes comandos para:

#### Iniciar o Wifi
```c++
newDevice.startWifi();
```
Caso seja a primeira conexão, o dispositivo entrará no modo AP. Para conectar basta, então, acessar a rede gerada pelo microcontrolador e configurá-la. No mais, o dispositivo tentará se reconectar com a rede salva anteriormente.

### Configurando o tipo de dispositivo
Devido a existência de diferentes tipos de dispositivos, é necessário configurar qual deles pretende-se utilizar. Para isso, basta adicionar ao código do projeto **um dos três** comandos abaixo:

```c++
newDevice.setDevice(accum); //para dispositivos que necessitam acumular dados coletados
newDevice.setDevice(intens); //para dispositivos que precisam somente coletar/enviar dados momentâneos
newDevice.setDevice(instant);// para dispositivos "instantâneos" que necessitam de controle de intensidade  
```
### Configurando nome dos eventos
**Antes de fazer** conexão com o servidor, é necessário configurar o nome dos eventos onde as trocas de mensagem ocorrerão. Os métodos, nomes padrões e a função de cada evento se encontra descritos na tabela abaixo.

Método | Valor Padrão | Descrição
------ | ----------- | --------
```newDevice.setSendingEvent("insiraNomeEscolhido");``` | device_send | Evento por onde o JSON de configurações é enviado para o server.
```newDevice.setReceivingEvent("insiraNomeEscolhido");``` | device_on | Evento que ativa o envio do JSON de configurações.
```newDevice.setReceivingConfigEvent("insiraNomeEscolhido");``` | device_config | Evento por onde o JSON de configurações é recebido do server.
```newDevice.setOnOffEvent("insiraNomeEscolhido");``` | device_onOff | Evento por onde o dispositivo recebe o comando de ligar/desligar.

### Iniciando conexão com o servidor
A biblioteca possui suporte para os protocolos Websocket,~~MQTT e HTTP~~ e para utilizar um desses é só utlizar **um dos** trechos de código abaixo:

```c++
#define HOST "190.000.0.000"

#define PORT "3000"

newDevice.startWSConnection(HOST, PORT); 
newDevice.startMQTTConnection(HOST, PORT); 
newDevice.startHTTPConnection(HOST, PORT); 
```

### LOOP
Para um correto funcionamento, é necessário adicionar o código abaixo no `void loop()`

```c++
newDevice.deviceHandle();
```

## Limitações e futuras melhorias:

- Protocolo HTTP ainda não implementado;
- Protocolo MQTT parcialmente implementado;
- Protocolo WebSocket implementado utilizando-se da biblioteca "SocketIOClient", pretende-se modificar para a "arduinoWebSockets" em breve;
