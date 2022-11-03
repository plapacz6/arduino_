/* reading analog input */
const int sensorPin = A0;

void setup() {
  Serial.begin(9600);
  for(int x = 2; x < 6; x++){
    pinMode(x == 6 ? 7 : x, OUTPUT);
    digitalWrite(x == 6 ? 7 : x, LOW);
  }  
}
#define VOLAGE_STEP ((1023 - 550)/5)
void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("analog read from variable resistor: ");  
  Serial.print(sensorVal);
  Serial.print("ADC\n");  
  
  for(int x = 6; x > 1; x--){
    if(sensorVal > 550 + VOLAGE_STEP * (x - 1)){    
      digitalWrite(x == 6 ? 7 : x  , HIGH);
    }
    else{
      digitalWrite(x == 6 ? 7 : x , LOW);
    }      
  }
  
  delay(250);  
}  
