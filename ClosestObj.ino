// defines pins numbers
const int trigPinL = 43;
const int echoPinL = 45;
const int trigPinM = 47;
const int echoPinM = 49;
const int trigPinR = 51;
const int echoPinR = 53;
const int encodL = 16;
const int encodR = 17;

// defines variables
long durationL, durationM, durationR;
int distanceL, distanceM, distanceR;
double lx, ly, rx, ry;



void setup() {
  const int trigPinL = 43;
  const int echoPinL = 45;
  const int trigPinM = 47;
  const int echoPinM = 49;
  const int trigPinR = 51;
  const int echoPinR = 53;
  Serial.begin(115200);
}

void loop() {
  //Left Sonar
  digitalWrite(trigPinL, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinL, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinL, LOW);
  durationL = pulseIn(echoPinL, HIGH);
  distanceL = durationL*0.034/2;

  //Middle Sonar
  digitalWrite(trigPinM, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinM, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinM, LOW);
  durationM = pulseIn(echoPinM, HIGH);
  distanceM = durationM*0.034/2;
  
  //Right Sonar
  digitalWrite(trigPinR, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinR, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinR, LOW);
  durationR = pulseIn(echoPinR, HIGH);
  distanceR = durationR*0.034/2;

  //Prints to the serial monitor which sonar returns the smallest distance and prints the distance
  if(distanceL <= distanceM && distanceL <= distanceR ) {
    Serial.print("Closest Object is to the left: "); Serial.print(distanceL); Serial.print("cm"); Serial.println();
  } else if (distanceM <= distanceL && distanceM <= distanceR ) {
    Serial.print("Closest Object is in front: "); Serial.print(distanceM); Serial.print("cm"); Serial.println();
  } else if (distanceR <= distanceL && distanceR <= distanceM ) {
    Serial.print("Closest Object is to the right: "); Serial.print(distanceR); Serial.print("cm"); Serial.println();
  }
  
  delay(1000);
}
