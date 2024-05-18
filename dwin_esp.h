#include "Arduino.h"
#define batu_dwin_H


void GO_PAGE(uint16_t PG){ 
  Serial.write(0x5A);     Serial.write(0xA5);
  Serial.write(0x07);     Serial.write(0x82);
  Serial.write((byte)00); Serial.write(0x84);
  Serial.write(0x5A);     Serial.write(0x01);
  Serial.write(PG >> 8);  Serial.write(PG % 256);
}


void ERASE_TEXT(int high_address, long d_Len){ 
  Serial.write(0x5A); 
  Serial.write(0xA5); 
  Serial.write(d_Len + 3); 
  Serial.write(0x82);

  Serial.write(high_address);
  Serial.write(0x00); // second
  for (int t = 0; t < d_Len; t++) {
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


void error_case(String error, int pic_id){
    GO_PAGE(2);
    ERASE_TEXT(0x50, error_length);
    if (error.length() > 100) {
        error = error.substring(0, 100);
    }
    error_length = error.length();
    SET_TEXT(0x50, error);
    GO_PAGE(pic_id);
    delay(1000 * 5);
    GO_PAGE(2);
    
    ERASE_TEXT(0x50, error_length);
    SET_TEXT(0x50, "loding");
    error_length = 6;
    delay(1000);

    GO_PAGE(pic_id);
}
