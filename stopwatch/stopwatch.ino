#include <LiquidCrystal.h>
#define pin_Start (13)
#define pin_Stop (12)

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
enum {ST_STOPPED, ST_RESET, ST_RUNNING} state;
struct stopwatch_T {
  unsigned ms;
  unsigned sec;
  unsigned min;
  unsigned hour;
} stopwatch;
stopwatch_T *pstopwatch = &stopwatch;

void print_stopwatch(void){
  lcd.setCursor(0, 1);
  lcd.print(String(pstopwatch->hour) + ":" + String(pstopwatch->min) + ":" + String(pstopwatch->sec) + "    ");  
}
void reset_stopwatch(void){
  pstopwatch->ms = 0;
  pstopwatch->sec = 0;
  pstopwatch->min = 0;
  pstopwatch->hour = 0;      
}
void print_msg(char *msg){
  lcd.setCursor(0, 0);
  lcd.print(msg);
}

void setup() {
  pinMode(pin_Start, INPUT);
  pinMode(pin_Stop, INPUT);

  reset_stopwatch();  
  
  lcd.begin(16, 2);  
  print_msg("stopwatch");  
  print_stopwatch();  
}

void loop() {
  switch(state) {
    case ST_STOPPED:
      while(digitalRead(pin_Start) == LOW){}                  
      reset_stopwatch();
      print_stopwatch();               
      state = ST_RESET;   
      delay(250);
      print_msg("press START  ");        
      break;
    case ST_RESET:      
      while(digitalRead(pin_Start) == LOW){}                 
      state = ST_RUNNING;      
      print_msg("press STOP   ");   
      break;
    case ST_RUNNING:
      pstopwatch->ms++;
      if(pstopwatch->ms > 999){
        pstopwatch->sec++;
        pstopwatch->ms = 0;                      
        if(pstopwatch->sec > 59){
          pstopwatch->min++;
          pstopwatch->sec = 0;
        }
        if(pstopwatch->min > 59){
          pstopwatch->hour++;
          pstopwatch->min = 0;
        }      
        if(pstopwatch->hour > 23){
          state = ST_STOPPED;
        }  
        print_stopwatch();
      }
      if(digitalRead(pin_Stop) == HIGH){        
        print_msg("STOPPED     ");
        delay(1000);
        print_msg("START->RESET");                
        state = ST_STOPPED;  
      }
      break;
  }
  delay(1);
}
