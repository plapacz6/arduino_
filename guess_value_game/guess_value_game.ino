#define adc_pin (A5)
#define led_good (2)
#define led_warning (3)
#define led_wrong (4)
#define read_pin (8)

int readedValue = 0;
String answer = "";
int answer_int = 0;
int try_nr = 0;
  
void setup() {
  pinMode(led_good, OUTPUT);
  pinMode(led_warning, OUTPUT);
  pinMode(led_wrong, OUTPUT);
  pinMode(read_pin, INPUT_PULLUP);
  Serial.begin(9600);
  readedValue = analogRead(adc_pin);  
}

void loop() {
  
  Serial.print("guess value\n> ");
  while(Serial.available() == 0){}
  
  answer = Serial.readStringUntil('\n');
  answer_int = answer.toInt();
  Serial.println(answer_int);
  try_nr++;        
  if( 
    (answer_int > readedValue + 50) ||
    (answer_int < readedValue - 50))
  {
      digitalWrite(led_warning, HIGH);
    if(try_nr > 1){
      digitalWrite(led_wrong, HIGH);
      Serial.println("it was: " + String(readedValue));
      try_nr = 0;
    }
    Serial.println("wrong answer");          
  }
  
  else {
    digitalWrite(led_good, HIGH);
    digitalWrite(led_warning, LOW);    
    Serial.println("good answer");
    Serial.println("it was: " + String(readedValue));
    try_nr = 0;
  }  

  if(try_nr == 0){
    delay(2000);
    Serial.println("again");     
    digitalWrite(led_wrong, LOW);
    digitalWrite(led_warning, LOW);
    digitalWrite(led_good, LOW);

    Serial.println("press read button");
    while(digitalRead(read_pin) == HIGH){}
    readedValue = analogRead(adc_pin);
  }
}

