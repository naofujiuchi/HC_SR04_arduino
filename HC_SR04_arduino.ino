// CAUTION!!
// connect echo pin to digital pin No. 2, 3, ... !!

int Trig = 8;
//int Echo = 9;
int Echo[7];
int Duration[7];
float Distance;

void setup() {
  int i;
  Serial.begin(9600);
  pinMode(Trig, OUTPUT);
  for(i = 0; i <= 6; i++){
    Echo[i] = i + 1;  // connect echo pin to digital pin No. 2 ~
    Duration[i] = 0;
  }
  pinMode(Echo[i], INPUT);
  Serial.write(1);
}

void loop() {
  int i;
  int h;
  int m;
  int s;
  // if (Duration>0) {
  if(Serial.available() == 3){
    h = Serial.read();
    m = Serial.read();
    s = Serial.read();
    Serial.flush();
    for(i = 1; i <= 6; i++){
      digitalWrite(Trig, LOW);
      delayMicroseconds(1);
      digitalWrite(Trig, HIGH);
      delayMicroseconds(1);
      digitalWrite(Trig, LOW);
      Duration[i] = pulseIn(Echo[i], HIGH);
      Serial.write(Duration[i] >> 8);
      Serial.write(Duration[i] & 0xff);
    }
    // Distance = Duration/2;
    // Distance = Distance*340*100/1000000; // ultrasonic speed is 340m/s = 34000cm/s = 0.034cm/us 
    // Serial.print(Duration);
    // Serial.print(" us ");
    // Serial.print(Distance);
    // Serial.println(" cm");
  }
  // delay(500);
}
