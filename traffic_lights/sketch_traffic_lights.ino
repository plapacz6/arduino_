uint8_t red_light = 12;
uint8_t yellow_light = 8;
uint8_t green_light = 4;
enum {ST_GREEN = 0, ST_YELLOW, ST_RED, ST_RY, ST_COUNT};
unsigned state = ST_RED;
void light_off(void);

void setup() {
  pinMode(red_light, OUTPUT);  
  pinMode(green_light, OUTPUT);
  pinMode(yellow_light, OUTPUT);
  
  pinMode(7, INPUT_PULLUP);  
  digitalWrite(red_light, HIGH);
  digitalWrite(yellow_light, LOW);
  digitalWrite(green_light, LOW);
}

void loop() {
  while(digitalRead(7) == HIGH){}
  state++;
  if(state == ST_COUNT){
    state = 0;
  }
  light_off();      
  switch(state){
    case ST_GREEN:
      digitalWrite(green_light, HIGH);
      break;
    case ST_YELLOW:
      digitalWrite(yellow_light, HIGH);  
      break;
    case ST_RED:
      digitalWrite(red_light, HIGH);
      break;
    case ST_RY:      
      digitalWrite(red_light, HIGH);
      digitalWrite(yellow_light, HIGH);
      break;
  }//switch
  delay(1000);    
}

void light_off(void){
      digitalWrite(red_light, LOW);
      digitalWrite(yellow_light, LOW);
      digitalWrite(green_light, LOW);  
}
