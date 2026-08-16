#include <Ultrasonic.h>
// Define pins for the Ultrasonic Sensor
#define TRIG_PIN 9
#define ECHO_PIN 10
// Define pins for L298N
#define ENA 5
#define IN1 6
#define IN2 7
// Define variables for distance measurement
Ultrasonic ultrasonic(TRIG_PIN, ECHO_PIN);
long distance;
// Setup function to initialize the pins
void setup() {
 // Initialize serial communication for debugging
 Serial.begin(9600);
 
 // Initialize the pins for L298N
 pinMode(ENA, OUTPUT);
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 // Initially, stop the L298N motor driver
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
 analogWrite(ENA, 0);
}
// Loop function to continuously check the distance and control the charging
void loop() {
 // Measure the distance to the vehicle
 distance = ultrasonic.Ranging(CM);
 
 // Print the distance for debugging
 Serial.print("Distance: ");
 Serial.print(distance);
 Serial.println(" cm");
 // If the vehicle is within 50 cm, start charging
 if (distance <= 50) {
 startCharging();
 } else {
 stopCharging();
 }
 // Wait for a short period before measuring again
 delay(500);
}
// Function to start charging
void startCharging() {
 // Enable the L298N to create the magnetic field in the coil
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 analogWrite(ENA, 255); // Set the speed (PWM) to maximum
}
// Function to stop charging
void stopCharging() {
 // Disable the L298N to stop the magnetic field in the coil
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
 analogWrite(ENA, 0);
}
