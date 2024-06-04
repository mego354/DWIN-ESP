#include "Arduino.h"
#define batu_dwin_H


void GO_PAGE(uint16_t PG){ 
  Serial.write(0x5A);     Serial.write(0xA5);
  Serial.write(0x07);     Serial.write(0x82);
  Serial.write((byte)00); Serial.write(0x84);
  Serial.write(0x5A);     Serial.write(0x01);
  Serial.write(PG >> 8);  Serial.write(PG % 256);
}


void ERASE_TEXT(int high_address, long Len){ 
  Serial.write(0x5A); 
  Serial.write(0xA5); 
  Serial.write(Len + 3); 
  Serial.write(0x82);

  Serial.write(high_address);
  Serial.write(0x00); // second
  for (int t = 0; t < Len; t++) {
    Serial.write(0x20);
  }
}

void SET_TEXT(int high_address, String textData){ 
  int d_Len = textData.length();

  Serial.write(0x5A); 
  Serial.write(0xA5); 
  Serial.write(d_Len + 3); 
  Serial.write(0x82);
  Serial.write(high_address);
  Serial.write(0x00);
  for(int i = 0; i < d_Len; i++)
  {
    Serial.write(textData[i]);
  }
}
