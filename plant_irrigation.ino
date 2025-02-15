const int moistureSensorPin = A0; // Sensor de umidade do solo conectado ao A0
const int pumpPin = 8; // Relé conectado ao pino 8
const int dryThreshold = 500; // Regulei para 500, mas deve ser refinado o ajuste do sensor para cada tipo de solo

void setup() {
  pinMode(moistureSensorPin, INPUT);
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, HIGH); // A bomba precisa estar desligada no inicio
  Serial.begin(9600);
  Serial.println("Plant Irrigation System Initialized!");
}

void loop() {
  int moistureLevel = analogRead(moistureSensorPin); //Ler a umidade do solo
  Serial.print("Soil Moisture Level: ");
  Serial.println(moistureLevel);

  if (moistureLevel > dryThreshold) {
    Serial.println("Soil is DRY! Watering the plant...");
    digitalWrite(pumpPin, LOW);  // Liga a bomba
    delay(2000);                 // Quantidade de água liberada em segundos
    digitalWrite(pumpPin, HIGH); // Desliga a bomba
    Serial.println("Watering complete.");
  } else {
    Serial.println("Soil is WET. No watering needed.");
  }

  delay(1000); // Delayzin antes a próxima leitura
}