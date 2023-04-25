#include <LiquidCrystal.h>
#define trigPin (12)
#define echoPin (13)
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

float distance = 0;

void print_msg(char *msg){
  lcd.setCursor(0, 0);
  lcd.print(msg);
}
void print_value(float val){
  lcd.setCursor(0, 1);
  lcd.print(String(val));
}

void measure_distance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  distance = pulseIn(echoPin, HIGH) / 58;   //58 from speed of sound
  if(distance > 400) distance = 400;        //max distance for HC-SR04 sensor
}

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  measure_distance();
  print_msg("distance in cm: ");
  print_value(distance);
  Serial.println(distance);
  delay(500);
}
