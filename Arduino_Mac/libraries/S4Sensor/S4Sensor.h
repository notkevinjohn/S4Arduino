/*
  S4Sensor.h - Library for reading the sensors supported
  Kevin Zack
  Sonoma State University
  NASA E/PO
  Released into the public domain.
*/
  #ifndef S4Sensor_h
  #define S4Sensor_h
  #include "Arduino.h"

  class S4Sensor
  {
        public:
               S4Sensor();
               void startBarometric();
               void getBarometric(long &pressure, double &temperature);
               
               void startHumidity();
               byte getHumidity(double &humidity, double &temperature);
              
               void startAccelerometer();
               void getAccelerometer(double &x, double &y, double &z);
               
               void startMagnetometer();
               void getMagnetometer(int &x, int &y, int &z);
               
               
        private:
           
                
  };
  #endif

