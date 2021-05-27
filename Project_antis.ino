#include <Servo.h>
Servo servo;

const int trigPin = 3;  
const int echoPin = 2;  

long duration; 
int distance;
int distance2; 

void setup(void) {
  Serial.begin(9600);
  servo.attach(4);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
sensor_function();
 Serial.println(distance);// Trouble shooting
 delay(200);
 
  if(distance <= 6) {
    if(distance == distance2){
      Serial.println("Spraying");
      
      servo.write(165);
      delay(200);
      
      servo.write(215);
      delay(200);
      
      servo.write(165);
      delay(200);

      servo.write(215);
      delay(200);

      servo.write(165);
      delay(200);
      
      servo.write(215);
      delay(200);
    }
  }
  distance2 = distance;
}

void sensor_function() {
  // Untuk mereset posisi Servo
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
}
