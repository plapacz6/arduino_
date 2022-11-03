

const int ledY_a = 7;
const int ledR = 5;
const int ledG = 4;
const int ledY = 3;

const int switchPin = 2;
int direction = 0;

void setup() {

  pinMode(ledY_a, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledY, OUTPUT);

  pinMode(switchPin, INPUT);
}

void loop() {

  int switchState;  
  
  switchState = digitalRead(switchPin);
  if(switchState == HIGH){
    direction = direction ? 0 : 1;
  }
  

  if(direction){
    digitalWrite(ledY_a, LOW);    
    
    digitalWrite(ledR, HIGH);
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    delay(250);
    
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, LOW);
    delay(250);

    digitalWrite(ledR, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, HIGH);
    delay(250);
  }
  else{
    digitalWrite(ledY_a, HIGH);
    
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, HIGH);
    delay(250);
    
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, LOW);
    delay(250);

    digitalWrite(ledR, HIGH);
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    delay(250);
  }
}
