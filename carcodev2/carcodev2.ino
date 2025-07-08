#include "BluetoothSerial.h"
int t = 300;
// Bluetooth Serial object
BluetoothSerial SerialBT;

// Motor pins
int motor1pin1 = 33;
int motor1pin2 = 27;

int motor2pin1 = 26;
int motor2pin2 = 25;

void setup() {
  // Motor pin setup
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  // Start USB Serial (for debugging - optional)
  Serial.begin(115200);
  Serial.println("Starting Bluetooth...");

  // Start Bluetooth Serial
  SerialBT.begin("ESP32_BT");  // Name to pair with
  Serial.println("Bluetooth started. Connect to 'ESP32_BT'");
}

void forward() {
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
}

void back() {
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}

void turnr() {
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}

void turnl() {
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
}

void off() {
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
}

void loop() {
  if (SerialBT.available()) {
    int number = SerialBT.parseInt();
    Serial.print("Received number: ");
    Serial.println(number); // USB debug output

        if(number == 1){
      Serial.print("d");
      forward();
      delay(t);
      off();
    }
        if(number == 2){
      Serial.print("d");
      back();
      delay(t);
      off();
    }
        if(number == 3){
      Serial.print("d");
      turnr();
      delay(t);
      off();
    }
      if(number == 4){
      Serial.print("d");
      turnl();
      delay(t);
      off();
    }
      if(number == 5){
        t = t - 100;
      SerialBT.println("speed  :");
      SerialBT.println(t);


    }
      if(number == 6){
        t = t + 100;
      SerialBT.println("speed  :");
      SerialBT.println(t);

      }
      
 
  }
}
