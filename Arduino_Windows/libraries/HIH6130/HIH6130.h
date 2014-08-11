/*
  HIH6130.h - Library for reading the sensors supported
  Kevin Zack
  Sonoma State University
  NASA E/PO
  Released into the public domain.
*/
  #ifndef HIH6130_h
  #define HIH6130_h
  #include "Arduino.h"
  
  class HIH6130
  {
        public:
               HIH6130();
               byte getHumidity(double &humidity, double &temperature);
               
        private:
               
  };
  #endif
