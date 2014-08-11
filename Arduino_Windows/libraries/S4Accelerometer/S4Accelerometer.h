/*
  S4Accelerometer.h - Library for reading the sensors supported
  Kevin Zack
  Sonoma State University
  NASA E/PO
  Released into the public domain.
*/
  #ifndef S4Accelerometer_h
  #define S4Accelerometer_h
  #include "Arduino.h"

  class S4Accelerometer
  {
        public:
               S4Accelerometer();
               void init(int activity, int inactivity, int actThresh, int inactThresh, int timeInact);
               void getAccel(double &accelX,double &accelY,double &accelZ);
               
        private:
  };
  #endif

