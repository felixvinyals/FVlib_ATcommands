#include "ATcommands.h"

#define readBufferTimeOut 100

ATcommands::ATcommands(SoftwareSerial &_port) {
  port = &_port;

}

byte ATcommands::readBuffer(char *buffer, byte sizeOfBuffer) {
  unsigned long timeGetIn;
  byte index;

  for(index = 0; index < sizeOfBuffer; index++) {
    buffer[index++] = '\0';
  }
  index = 0;
  timeGetIn = millis();
  while((timeGetIn - millis()) < readBufferTimeOut) {
    if ((*port).available() > 0) {
      timeGetIn = millis();
      buffer[index++] = (*port).read();
    }
  }
  // Print the buffer reading:
  //Serial.println("Buffer conte:");
  /*for(index = 0; index < sizeOfBuffer; index++) {
    Serial.print(String(index) + String(" "));
    Serial.println((byte)buffer[index], DEC);
  }*/
  return index;
}

byte ATcommands::foundOK(char *buffer, byte sizeOfBuffer) {
  byte size = readBuffer(buffer, sizeOfBuffer);
  Serial.println(String("Size: ") + size);
  Serial.println("al reves:");
  for (byte index = (size - 1); index != 255; index--) {
    // Print the buffer reading:
    //Serial.print(String(index) + String(" "));
    //Serial.println(buffer[index], DEC);
    if (buffer[index] == 10) {
      if ((buffer[index - 1] == 13) &&
      (buffer[index - 2] == 75) && (buffer[index - 3] == 79)) {
          return 1;
      }
      if ((buffer[index - 1] == 13) &&
      (buffer[index - 2] == 82) && (buffer[index - 3] == 79) &&
      (buffer[index - 4] == 82) && (buffer[index - 5] == 82) &&
      (buffer[index - 6] == 69)) {
          return 0;
      }
    }
  }
  return 255;
}
