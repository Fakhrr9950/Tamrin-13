/*
     Ultrasonic Sensor HC-SR05/4 and Arduino
      by Hanie Kiani
   https://electropeak.com/learn
*/
long duration;
int distance;

const int trig = 9; //sets the trig pin 9
const int echo = 10;//sets the echo pin10


void setup() {
  pinMode(trig, OUTPUT); // Sets the trigPin as an Output
  pinMode(echo, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  distance = calculateDistance();
  Serial.print("distance =");
  Serial.print(distance);
  Serial.println("cm");
  delay(500);



}
int calculateDistance() {

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance = duration * 0.034 / 2;
  return distance;
}

