
#include <LiquidCrystal.h>
extern volatile unsigned long timer0_millis;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
String rcvgst;
int gst=20;
  
void setup() {
  Serial.begin(9600);
  
  lcd.begin(16, 2);
  
  lcd.print("Time left:");
}

void loop() {
  if (Serial.available()>0){
    
    rcvgst=Serial.readStringUntil('\n');
    gst=rcvgst.toInt();
  }
    
    while(millis() <= gst*1000){
    
        lcd.setCursor(0, 1);

        lcd.print(gst -  millis()/1000);
        lcd.print(' ');
  }
    gst=5;
  	noInterrupts ();
  	timer0_millis = 0;
 	interrupts ();

 
  }
 

