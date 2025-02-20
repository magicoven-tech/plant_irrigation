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
const int pumpPin = 8;           // Relé conectado ao pino 8
const int dryThreshold = 500;    // Limiar para solo seco
const int wetThreshold = 300;    // Limiar para solo muito molhado
const unsigned long wateringInterval = 60000; // Intervalo mínimo entre regas (60 segundos)

unsigned long lastWateringTime = 0; // Armazena o tempo da última rega

void setup() {
  pinMode(moistureSensorPin, INPUT);
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, LOW); // A bomba inicia desligada
  Serial.begin(9600);
  Serial.println("Sistema de irrigação de plantas inicializado!\n");
}

void loop() {
  int moistureLevel = analogRead(moistureSensorPin); // Ler a umidade do solo
  Serial.print("Nível de umidade do solo: ");
  Serial.println(moistureLevel);

  // Verificar se o solo está seco e se o intervalo mínimo entre regas foi respeitado
  if (moistureLevel > dryThreshold && (millis() - lastWateringTime) > wateringInterval) {
    Serial.println("O solo está SECO! Regando a planta...\n");

    digitalWrite(pumpPin, HIGH); // Liga a bomba
    delay(2000); // Tempo de rega (2 segundos)
    digitalWrite(pumpPin, LOW); // Desliga a bomba

    lastWateringTime = millis(); // Atualiza o tempo da última rega
    Serial.println("Regagem concluída.\n");
  } 
  
  // Verificar se o solo está muito molhado
  else if (moistureLevel < wetThreshold) {
    Serial.println("O solo está MUITO MOLHADO! Não é necessário regar por um bom tempo.\n");
    delay(10000); // Delay maior, pois o solo está muito úmido
  }
  
  // Solo está úmido, mas não precisa de rega
  else {
    Serial.println("O solo está MOLHADO. Não é necessário regar.\n");
  }

  delay(1000); // Delay antes da próxima leitura
}

/**

Tempo de Rega Proporcional, ajusta o tempo de rega com base no nível de umidade.

int wateringTime = map(moistureLevel, dryThreshold, 1023, 5000, 1000); // Tempo de rega proporcional
digitalWrite(pumpPin, HIGH);
delay(wateringTime);
digitalWrite(pumpPin, LOW);

**/