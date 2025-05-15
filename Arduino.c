const int soilMoisturePin = A0;    // Analog pin connected to soil moisture sensor
const int pumpPin = 7;             // Digital pin connected to relay controlling pump

const int moistureThreshold = 400; // Adjust this threshold based on your sensor

void setup() {
  Serial.begin(9600);
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, LOW); // Pump off initially
}

void loop() {
  int moistureLevel = analogRead(soilMoisturePin);
  Serial.print("Soil moisture level: ");
  Serial.println(moistureLevel);

  if (moistureLevel < moistureThreshold) {
    // Soil is dry
    digitalWrite(pumpPin, HIGH); // Turn pump ON
    Serial.println("Pump ON - Watering the plant");
  } else {
    digitalWrite(pumpPin, LOW);  // Turn pump OFF
    Serial.println("Pump OFF - Soil moist");
  }

  delay(2000); // Wait 2 seconds before next check
}
