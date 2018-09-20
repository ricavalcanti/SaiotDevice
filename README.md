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
2. Deve-se também, fazer o *download* das seguintes bibliotecas (para comunicação): [WiFiManager](https://github.com/apenaz/WiFiManager) e [PubSubClient](https://github.com/knolleary/pubsubclient).
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
	
- Para um **controlador** deve-se passar três parâmetros do tipo **Strings**, necessariamente nesta sequência: uma **key** (dado para ser usado como referência daquele controlador), uma **tag** (apenas para identificação), e a **class** do controlador (que indica como ele será renderizado na interface de usuário). Uma forma alternativa é passar todo o seu JSON de configuração. A utilização desse segundo construtor é uma boa alternativa para caso seu controlador tenha mais atributos. Saiba mais detalhes sobre os [controladores aqui](https://danielaraujorn.github.io/blog/2018/09/18/controladores.html)). 
	
	```c++
	SaIoTController myController(controllerKey, controllerTag, controllerType);
	String jsonConfig;
	SaIoTController myController(jsonConfig);
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
	SaIoTSensor mySensor(sensorKey,sensorTag,dataUnit,dataType);
	String jsonConfig;
	SaIoTSensor mySensor(jsongConfig);
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
1. Na função **Setup** é preciso associar os **Sensores** e **Controladores**, previamente instanciados, com o **Device**, utilizando os seguintes métodos da classe SaIoTDeviceLib, para **cada** controlador e sensor:

	```c++
	myDevice.addController(&SaIoTController);
	myDevice.addSensor(&SaIoTSensor);
	```
2.  Iniciando a parte de comunicação, o objeto do tipo **WiFiClient** e a função de **Callback**, explicada anteriormente, devem ser passadas . A função de Callback deverá ter a mesma estrutura do exemplo a seguir.

	```c++
	myDevice.preSetCom(&WiFiClient, &callback);

	```

	```c++
	// implementação do callback
	void callback(char* topic, byte* payload, unsigned int length){
		String payloadS;	
  	for (unsigned int i=0;i<length;i++) {
    	payloadS += (char)payload[i];
	}
  	if(strcmp(topic,myDevice.getSerial().c_str()) == 0){
		//insira aqui o que o device deve fazer ao receber algo nesse tópico
  	}
  	if(strcmp(topic,(myDevice.getSerial()+myController.getKey()).c_str()) == 0){
    	//insira aqui o que o device deve fazer ao receber algo nesse tópico
  	}
	 if(strcmp(topic,(myDevice.getSerial()+mySensor.getKey()).c_str()) == 0){
      //insira aqui o que o device deve fazer ao receber algo nesse tópico
			
  	}
		//inclua outras condições para todos os controllers e sensores
	}
	
	```
 **OBS.:** Para enviar dados do sensor, a classe **SaIoTSensor** dispõe de dois métodos, ambos recebendo o dado do tipo **double** e uma delas recebendo também a data e hora do dispositivo.

 ```c++
 	double valor;
	String dataHora;

	mySensor.sendData(valor);
	mySensor.sendData(valor, dataHora);
 ```
 Caso opte pela utilização do segundo método. O usuário será responsável pelo controle do tempo de envio. Enquanto no primeiro, a data é sincronizada com o servidor na primeira conexão e gerenciada pelo próprio microcontrolador.


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
Um exemplo de uso pode ser consultado na pasta **examples**. Nele é feito um Device com apenas um controlador e um sensor. Onde é possível também se ter uma dica de como configurar o tempo de envio dos dados do sensor.

**OBS.:** Caso seja a primeira conexão, o dispositivo entrará no modo AP. Para conectar, basta então, acessar a rede gerada pelo microcontrolador e configurá-la. No mais, o dispositivo tentará se reconectar com a rede salva anteriormente.


