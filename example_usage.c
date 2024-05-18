#define SERIAL_BAUDRATE 9600
#include "batu_dwin.h"

void setup() {
  Serial.begin(9600);
  delay(1000);
}

void loop() {
// get page 1
  GO_PAGE(1);

// write in vp 1000
  SET_TEXT(0x10, "example");
  delay(3000);

// erase letters in vp 1000
  ERASE_TEXT(0x10, 7) // example length
  delay(3000);

// get page 0
  GO_PAGE(0);
}
