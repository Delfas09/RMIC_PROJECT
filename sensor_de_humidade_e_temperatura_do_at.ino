//código tirado de https://www.arduinoportugal.pt/utilizar-sensor-dht11-sensor-temperatura-humidade/
#include "DHT.h"

#define pinDHT11 Pino(defenir o pino do nodemcu)  //pino ligação do DHT11
#define intervaloleituras 1 * 60    //intervalo de n*60, n em minutos para intervalo entre medidas
#define nmedidas 5                  //variavel utilizada para indicar o numero de medidas efetuados
#define debug false //cena do debug

/**************** VARIAVEIS **********************/
DHT dht;                             //variavel do sensor de temperatura e humidade
unsigned int humidade = 0;           //variavel para armazenar valor de humidade
unsigned int temperatura = 0;        //variavel para armazenar valor de temperatura
unsigned long ultimamedida;          //usado para armazenar o valor em milisegundos da ultima medida
/***************************************************/

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);    //velocidade de comunicacao por porta serie com o PC por USB
 dht.setup(pinDHT11);   //definicao do pino de ligacao do sensor DHT11
 Serial.println("A iniciar a leitura de temperatura e humidade...");
  delay(1000);    //depois de alimentar o sensor aguarda que a tensao estabilize
  temperaturahumidade();
  ultimamedida = millis() / 1000;
}

void loop() {
  // put your main code here, to run repeatedly:
  if (((millis() / 1000 - ultimamedida)) > (intervaloleituras)) {    //funcao que e despoletada a cada intervaloleituras
    temperaturahumidade();
    ultimamedida = millis() / 1000;
  }
}

void  temperaturahumidade() {
   humidade = 0; //reset à variavel temperatura para não conter valores da última medição
   temperatura = 0; //reset à variavel humidade para não conter valores da última medição
   unsigned int h = 1; //variavel para contar o numero de vezes que é adquirida a temperatura
    while (h <= nmedidas) {   //ciclo utilizado para adquirir nmedidas de temperatura
      unsigned int Humid = dht.getHumidity(); //variavel utilizada para armazenar a humidade atual
      unsigned int Tempe = dht.getTemperature(); //variavel utilizada para armazenar a temperatura atual
      String  estadosensor = dht.getStatusString();//variavel utilizada para armazenar o estado do sensor
          if (debug) {
      Serial.print("h = ");
      Serial.print(h);
      Serial.print(" TEMP (*C) = ");
      Serial.print(Tempe);
      Serial.print(" HUMID (%) = ");
      Serial.print(Humid);
      Serial.print(" ESTADO = ");
      Serial.println(estadosensor);
      }
     if ((estadosensor == "OK") and (Humid < 100) and (Tempe < 60)) {
      humidade += Humid;
      temperatura += Tempe;
    } else {
      if (debug) {
        Serial.println("Necessario mais uma medida por erro no resultado obtido.");
      }
      h -= 1;
    }
    delay(dht.getMinimumSamplingPeriod());
    h += 1;
   }
     humidade = humidade / (nmedidas);                //média da medida de humidade
  temperatura = temperatura / (nmedidas);          //média da medida de temperatura

  Serial.println("");
  Serial.println("********* VALORES MEDIOS **********");
  Serial.print("   ");
  Serial.print("TEMP (*C) = ");
  Serial.print(temperatura);
  Serial.print(" HUMID (%) = ");
  Serial.print(humidade);
  Serial.println("  ");
  Serial.println("***********************************");

}
