
/*
based on arduino video tutorial
*/
const int ledPin = 13;
const int piezzoPin = 4;
const int photoResistorPin = A0;
int soundDuration = 20;

int sensorValue;
int sensorHigh;
int sensorLow;


void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  while(millis() < 5000) {
    sensorValue = analogRead(photoResistorPin);
  }
  if(sensorValue > sensorHigh){
    sensorHigh = sensorValue;
  }
  if(sensorValue < sensorLow){
    sensorLow = sensorValue;
  }
  digitalWrite(ledPin, LOW);
}

const int min_Hz = 50;
const int max_Hz = 4000;
void loop() {
  sensorValue = analogRead(photoResistorPin);
  int pitch = map(sensorValue, sensorLow, sensorHigh, min_Hz,max_Hz);
  
  tone(piezzoPin, pitch, soundDuration);

  delay(10);
}
