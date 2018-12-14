#include <NewPing.h>
#define TRIGGER_PIN  12
#define ECHO_PIN     13
#define MAX_DISTANCE 200
#define MOTOR_A_1A 2
#define MOTOR_A_1B 4
#define MOTOR_B_1A 6
#define MOTOR_B_1B 8

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  // Motor pins need to be OUTPUT.
  Serial.begin(115200);
  pinMode(MOTOR_A_1A, OUTPUT);
  pinMode(MOTOR_A_1B, OUTPUT);
  pinMode(MOTOR_B_1A, OUTPUT);
  pinMode(MOTOR_B_1B, OUTPUT);
}

void wheelABackwards() {
  digitalWrite(MOTOR_A_1A, HIGH);
  digitalWrite(MOTOR_A_1B, LOW);
}

void wheelAForwards() {
  digitalWrite(MOTOR_A_1A, LOW);
  digitalWrite(MOTOR_A_1B, HIGH);
}

void wheelAStop() {
  digitalWrite(MOTOR_A_1A, LOW);
  digitalWrite(MOTOR_A_1B, LOW);
}

void wheelBForwards() {
  digitalWrite(MOTOR_B_1A, HIGH);
  digitalWrite(MOTOR_B_1B, LOW);
}

void wheelBBackwards() {
  digitalWrite(MOTOR_B_1A, LOW);
  digitalWrite(MOTOR_B_1B, HIGH);
}

void wheelBStop() {
  digitalWrite(MOTOR_B_1A, LOW);
  digitalWrite(MOTOR_B_1B, LOW);
}

void loop() {
 // use the wheel... methods to drive one motor.
 
  delay(250);
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm());
  Serial.println("cm");

  if (sonar.ping_cm() <= 25){

   wheelAStop();
   wheelBStop();
   delay(1000);
   wheelBForwards();
   delay(500);
   
  }
  else
  {
   wheelAForwards();
   wheelBForwards();  
   }
}
