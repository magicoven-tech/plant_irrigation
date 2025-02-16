/** 
##################################################
#
# Plant irrigation by Arduino 
# -- Using microcontroller, relay and water pump to water our plants.
#
# by Magic Oven (c) 2025
#
##################################################
**/

const int moistureSensorPin = A0; // Sensor de umidade do solo conectado ao A0
const int pumpPin = 8; // Relé conectado ao pino 8
const int dryThreshold = 500; // Regulei para 500, quando estiver seco, mas deve ser refinado o ajuste do sensor para cada tipo de solo
const int wetThreshold = 300; // Rebulei para 300, quando estiver muito molhado, mas deve ser refinado o ajuste do sensor para cada tipo de solo

void setup() {
  pinMode(moistureSensorPin, INPUT);
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, HIGH); // A bomba precisa estar desligada no inicio
  Serial.begin(9600);
  Serial.println("Sistema de irrigação de plantas inicializado!\n");
}

void loop() {
  int moistureLevel = analogRead(moistureSensorPin); //Ler a umidade do solo
  Serial.print("Nível de umidade do solo:");
  Serial.println(moistureLevel);

  if (moistureLevel > dryThreshold) {
    Serial.println("O solo está SECO! Regando a planta...\n");

    digitalWrite(pumpPin, HIGH); // Liga a bomba

    delay(2000); // Quantidade de água liberada em segundos

    digitalWrite(pumpPin, LOW); // Desliga a bomba
    Serial.println("Regagem concluída.\n");
  } 
  
  else if (moistureLevel < wetThreshold) {
    Serial.println("O solo está MUITO MOLHADO! Não é ncessário regar por um bom tempo.\n");
    
    delay(10000); // Delay maior, pois tem muita umidade no solo
  }
  
  else 
  {
    Serial.println("O solo está MOLHADO. Não é necessário regar.\n");
  }

  delay(1000); // Delayzin antes a próxima leitura
}