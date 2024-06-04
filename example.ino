#include "batu_dwin.h"
#define SERIAL_BAUDRATE 9600

void setup() {
  Serial.begin(SERIAL_BAUDRATE);
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
