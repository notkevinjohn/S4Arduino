/*
  S4GPS.h - Library for reading the GPS 
  Kevin Zack
  Sonoma State University
  NASA E/PO
  Released into the public domain.
*/
  #ifndef S4GPS_h
  #define S4GPS_h
  #include "Arduino.h"
  
  
  class S4GPS
  {
        public:
               S4GPS();
               void begin(int buadRate);
               //void checkSum();
               bool getGPS(char* gps);
               uint8_t parseHex(char c);
               void Configure();
               void setupGPS(uint8_t* mesg, uint8_t bits);
        private:
                int buadRate;
                
  };
  #endif
