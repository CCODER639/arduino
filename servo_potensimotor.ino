// Potentiometer is connected to GPIO 34 (Analog ADC1_CH6) 
const int potPin = 34;
// variable for storing the potentiometer value
int potValue = 0;
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Servo pulse parameters (for MG996R)
#define SERVO_MIN  102  // Adjusted for ~0°
#define SERVO_MAX  512  // Adjusted for ~180°

#define SERVO_CHANNEL 0 // PCA9685 channel the servo is connected to

// Function to convert angle to pulse length
uint16_t angleToPulse(int angle) {
  return map(angle, 0, 180, SERVO_MIN, SERVO_MAX);
}

void setup() {
  Serial.begin(115200);
  pwm.begin();
  pwm.setPWMFreq(50); // 50Hz for servos
  delay(10); // Wait for PWM to stabilize
  Serial.begin(115200);
  delay(1000);

  // Move servo to 90°
  
}

void loop() {
  potValue = analogRead(potPin);
  Serial.println(potValue/22.75);
  
  int pulse = angleToPulse(potValue/22.75);
  pwm.setPWM(SERVO_CHANNEL, 0, pulse);
  Serial.println("Moved servo to 90 degrees");
  delay(100);
  // Do nothing
}
