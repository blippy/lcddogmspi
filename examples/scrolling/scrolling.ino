#include <LCDdogmSPI.h>

#define CSB_PIN 10
#define RS_PIN 12
#define LCD_LINES 3

// This initializes for a 3 LINES display

LCDdogmSPI lcd = LCDdogmSPI(LCD_LINES, CSB_PIN, RS_PIN);

char msg[] = "Hello world...  ";

void printMsg() {
  lcd.cursorTo(0,0);
  lcd.println(msg);
}

void setup() {
  lcd.init();
  printMsg();
}

void shiftMsg() {
  // cyclically shift the message 1 char left
  char c0 = msg[0]; // store the first char for later
  memmove(msg, msg+1, strlen(msg) -1); // shift left (overwrites first char)
  msg[strlen(msg)-1] = c0; // put the first char on the end
}

void loop() {
  delay(100); 

  shiftMsg();
  printMsg();
  
  
  
}
