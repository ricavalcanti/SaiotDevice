# SaIoTDevice

Biblioteca responsável pela comunicação entre dispositivos que usam ESP8266 com middleware do projeto SaIoT-UFRN.

## Conteúdo:
- Gerenciamento de *WiFi* (WiFiManager);
- Manipulação de JSONs;
- Suporte a diferentes tipos de dispositivos (Analógicos, Digitais, Acumuladores, dentre outros);
- Suporte ao protocolo MQTT.

## Como usar:
### Incluir  no projeto
1. Para usar a biblioteca basta, primeiramente, fazer o *download* do código, extrair e copiar para a pasta de bibliotecas do seu projeto;
2. Deve-se também, fazer o *download* das seguintes bibliotecas (para comunicação): [WiFiManager](https://github.com/tzapu/WiFiManager) e [PubSubClient](https://github.com/knolleary/pubsubclient).
3. Incluir no arquivo fonte as instruções: 
```c
#include <SaIoTDeviceLib.h>
```

### Escopo Global 
1. No **escopo de varáveis globais**, deve-se instanciar um objeto  tipo **WiFiClient**, e um objeto do tipo **SaIoTDeviceLib** com seus respectivos atributos (você deverá passar 3 Strings: o nome do Device, o Serial (link para a postagem) e o email, utilizado no SaIoT, de quem irá cadastrar o dispositivo em questão, respectivamente).
	  ```c++
	WiFiClient espClient;
	SaIoTDeviceLib myDevice(deviceName, deviceSerial, emailUser);
	```
2. Deve-se inicializar os componentes do Device a ser criado (todos os seus controladores e sensores, utilizando as classes **SaIoTController** e **SaIoTSensor**):
	
- Para um **controlador** deve-se passar como parâmetros **3 Strings**, necessariamente nesta sequência: uma **key** (dado para ser usado como referência daquele controlador), uma **tag** (apenas para identificação), e a **class** do controlador (que indica como ele será renderizado no front); uma forma alternativa é passar todo o seu JSON de configuração. A utilização desse segundo construtor é uma boa alternativa para caso seu controlador tenha mais atributos (consultar documentação do middleware). 
	
	```c++
	SaIoTController(controllerKey, controllerTag, controllerType);
	String jsonConfig;
	SaIoTController(jsonConfig);
	```

	```json
	{	
		"key": "on/off",
		"tag": "simpleToggle",
		"class":"onoff"
	};
	```
- Para um **sensor** deve-se passar como parâmetros **4 Strings**, necessariamente nesta sequência: uma **key** (dado para ser usado como referência daquele sensor), uma **tag**, a **unidade de medida** (para o dado a ser mensurado, como por exemplo Litros) e o **tipo** do dado (Boolean, String, Point, Number); assim como para o controlador, há uma forma alternativa de construtor no qual deve-se ser passado todo o seu JSON de configuração. 
	```c++
	SaIoTSensor(sensorKey,sensorTag,dataUnit,dataType);
	String jsonConfig;
	SaIoTSensor(jsongConfig);
	```
	```json
	{	
		"key": "hidro01",
		"tag": "hidrometro_01",
		"unit":"Litros",
		"type":"number"
	};
	```
### Setup
1. Na função **Setup** é preciso associar os **Sensores** e **Controladores** com o **Device**, utilizando os seguintes métodos da classe SaIoTDeviceLib, para **cada** controlador e sensor:

	```c++
	myDevice.addController(&SaIoTController);
	myDevice.addSensor(&SaIoTSensor);
	```
2.  Iniciando a parte de comunicação, o objeto do tipo **WiFiClient** e a função de **Callback**, explicada anteriormente, devem ser passadas . A função de Callback deverá ter a mesma estrutura do exemplo a seguir.

	```c++
	myDevice.preSetCom(&WiFiClient, &callback);
	// Botar a implementação do callback
	```
3.  Iniciar a comunicação com o servidor chamando o seguinte método, passando uma **String** com a **senha do usuário**.

	```c++
	myDevice.startDefault(senhaDoUsuario);
	```
### Loop

1. Por último, é necessário chamar o método handleLoop no escopo da função **Loop**.
	```c++
	bool handleLoop(void);

	```
### Exemplo
Um exemplo de uso pode ser consultado na pasta **examples**. Nele é feito um Device com apenas um controlador para ligar e desligar uma lâmpada.

### Configurando
Uma vez incluída, a biblioteca facilitará várias etapas do seu projeto. Aproveitando o objeto exemplo criado no item anterior temos os seguintes comandos para:

#### Iniciar conexão com a internet e com o servidor
```c++
void setup(){
	mydevice.start(SERIAL,HOST,PORT,POST)
}
`````
sendo:

| NOME |TIPO  | DESCRIÇÃO
|:------:|:------:|:-------:|
| Serial | char* |*em construção*|
|Host|char*|*em construção*|
|Port|int|Porta de comunicação |
|Post|int|Nome do evento que irá receber os dados

**OBS.:** Caso seja a primeira conexão, o dispositivo entrará no modo AP. Para conectar, basta então, acessar a rede gerada pelo microcontrolador e configurá-la. No mais, o dispositivo tentará se reconectar com a rede salva anteriormente.

### Adicionar sensores
Os sensores do seu dispositivo podem ser adicionados por meio do seguinte método
```c++
void setup(){
[...]
	mydevice.addSensors(key,isSync,deadband,timeout,isDigital,isAcumm,label,valor,unit);
}
```
onde

| NOME |TIPO  | DESCRIÇÃO
|:----:|:----:|:-----:|
| Key| char* |*em construção*|
|Is Sync|bool|*true* se o dispositivo se comunicar com o servidor de forma síncrona.|
|Deadband|int|*em construção*|
|Timeout| int|*em construção*|
|Is Digital| bool|*true* se o dispositivo for digital, *false* se for analógico.|
|Is Acumm|bool| *true* se o dispositivo for do tipo acumulador.|
|Label|char*|*em construção*|
|Valor| double| Dado coletado do ambiente pelo sensor.|
|Unit|char*| Unidade referente ao valor enviado.|
