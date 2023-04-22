#define adc_pin (A5)

int readedValue = 0;
constexpr size_t led_size = 5;
uint8_t led[led_size] = {2, 3, 4, 5, 6};

void turn_on_led(size_t turn_on);

void setup() {
  Serial.begin(9600);
  for(size_t i = 0; i < led_size; i++){
    pinMode(led[i], OUTPUT);
  } 
}

void loop() {
  readedValue = analogRead(adc_pin);
  turn_on_led( map(readedValue, 0, 1023, 1, 5));
  Serial.println( String(map(readedValue, 0, 1023, 1.0, 5.0)) + " volts");
  delay(250);
}

void turn_on_led(size_t turn_on){
    turn_on -= 1;
    for(size_t i = 0; i < led_size; i++){
      digitalWrite(led[i], i == turn_on ? HIGH : LOW);
    }   
}
