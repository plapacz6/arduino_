#define led_green (4)
#define led_red (12)

String receivedData = "";

void setup() {
  pinMode(led_green, OUTPUT);
  pinMode(led_red, OUTPUT);
  Serial.begin(9600);  
  digitalWrite(led_green, LOW);
  digitalWrite(led_red, LOW);
}

void loop() {
  if(Serial.available() > 0){
    receivedData = Serial.readStringUntil('\n');
    if(receivedData == "green on"){
      digitalWrite(led_green, HIGH);
    } 
    else
    if(receivedData == "green off"){
      digitalWrite(led_green, LOW);
    }
    else
    if(receivedData == "red on"){
      digitalWrite(led_red, HIGH);
    }
    else
    if(receivedData == "red off"){
      digitalWrite(led_red, LOW);
    }
    else
      Serial.println("not known command!");
  }
}
