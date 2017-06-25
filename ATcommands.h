
#ifndef ATcommands_h
  #define ATcommands_h
  #include <Arduino.h>
  #include <SoftwareSerial.h>

  class ATcommands {
    public:
      /* Constructor
       * @param: &_port: the SoftwareSerial port connected to the GSM/GPRS module
       */
      ATcommands(SoftwareSerial &_port);


      /* Looks the end of the command return for an "OK" or "ERROR"
       * @param:
       *  buffer: where will be saved the readed buffer
       *  sizeOfBuffer: size to read
       * @return:
       *  0: "ERROR" found at the end
       *  1: "OK" found at the end
       *  255: No "ERROR" or "OK" found or timeout reading buffer
       */
      byte foundOK(char *buffer, byte sizeOfBuffer);

    private:
      SoftwareSerial *port; // UART port connected to GPRS/GSM module
      byte readBuffer(char *buffer, byte sizeOfBuffer); // Max buffer size: 254 bytes


  };
#endif
