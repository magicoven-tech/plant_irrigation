const int moistureSensorPin = A0; // Sensor de umidade do solo conectado ao A0
const int pumpPin = 8; // Relé conectado ao pino 8
const int dryThreshold = 500; // Regulei para 500, mas deve ser refinado o ajuste do sensor para cada tipo de solo

void setup() {
  pinMode(moistureSensorPin, INPUT);
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, HIGH); // A bomba precisa estar desligada no inicio
  Serial.begin(9600);
  Serial.println("Sistema de irrigação de plantas inicializado!");
}

void loop() {
  int moistureLevel = analogRead(moistureSensorPin); //Ler a umidade do solo
  Serial.print("Nível de umidade do solo:");
  Serial.println(moistureLevel);

  if (moistureLevel > dryThreshold) {
    Serial.println("O solo está SECO! Regando a planta...");
    digitalWrite(pumpPin, HIGH);  // Liga a bomba
    delay(2000);                 // Quantidade de água liberada em segundos
    digitalWrite(pumpPin, LOW); // Desliga a bomba
    Serial.println("Rega concluída.");
  } else {
    Serial.println("O solo está MOLHADO. Não é necessário regar.");
  }

  delay(1000); // Delayzin antes a próxima leitura
}