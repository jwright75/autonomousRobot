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

  if (abs(distanceM-distanceL) <= (max(distanceM, distanceL)*0.1) && abs(distanceM-distanceR) <= (max(distanceM, distanceR)*0.1)) {
    Serial.println("Larger");
  } else if (abs(distanceM-distanceL) <= (max(distanceM, distanceL)*0.1) || abs(distanceM-distanceR) <= (max(distanceM, distanceR)*0.1)) {
    Serial.println("Smaller");
  } else {
    Serial.println("Smaller");
  }
  
  delay(1000);
}
