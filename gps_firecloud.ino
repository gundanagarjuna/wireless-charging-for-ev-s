// Alcohol Detection System

#define MQ_PIN A0
#define RED_LED 8
#define GREEN_LED 9
#define BUZZER 10

int sensorValue = 0;
int threshold = 400; // Adjust this value after testing

void setup() {
  Serial.begin(9600);

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BUZZER, LOW);
}

void loop() {
  sensorValue = analogRead(MQ_PIN);
  
  Serial.print("Alcohol Value: ");
  Serial.println(sensorValue);

  if (sensorValue > threshold) {
    // Alcohol Detected
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BUZZER, HIGH);
  } else {
    // Safe Condition
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BUZZER, LOW);
  }

  delay(500);
}