/*
  HMC5883L.h - Library for reading the sensors supported
  Kevin Zack
  Sonoma State University
  NASA E/PO
  Released into the public domain.
*/
  #ifndef HMC5883L_h
  #define HMC5883L_h
  #include "Arduino.h"
  
  class HMC5883L
  {
        public:
               HMC5883L();
               void init();
               void getMagnetometer(int &magX, int &magY, int &magZ);
               
        private:
               
  };
  #endif
