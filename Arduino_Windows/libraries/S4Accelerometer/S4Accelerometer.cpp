 /*
  S4Accelerometer.cpp - Library for the Sensors Supported by S4
  Kevin Zack
  Sonoma State University
  NASA E/PO
  Released into the public domain.
*/
  #include "Arduino.h"
  #include "S4Accelerometer.h"
  
  #include "../ADXL345/ADXL345.h"
  #include "../ADXL345/ADXL345.cpp"
  
  ADXL345 adxl;
    
  S4Accelerometer::S4Accelerometer()
  {
  }
  
  void S4Accelerometer::init(int activity, int inactivity, int actThresh, int inactThresh, int timeInact)
  {
        /******setup accel **********/
      adxl.powerOn();
      adxl.setActivityThreshold(actThresh); //62.5mg per increment
      adxl.setInactivityThreshold(inactThresh); //62.5mg per increment
      adxl.setTimeInactivity(timeInact); // how many seconds of no activity is inactive?
 
  //look of activity movement on this axes - 1 == on; 0 == off 
      adxl.setActivityX(activity);
      adxl.setActivityY(activity);
      adxl.setActivityZ(activity);
 
  //look of inactivity movement on this axes - 1 == on; 0 == off
      adxl.setInactivityX(inactivity);
      adxl.setInactivityY(inactivity);
      adxl.setInactivityZ(inactivity);
  }
  
  void S4Accelerometer::getAccel(double &accelX,double &accelY,double &accelZ)
  {
       int intAccelX, intAccelY, intAccelZ;
       adxl.readAccel(&intAccelX, &intAccelY, &intAccelZ);
       accelX = (double)intAccelX/255.0;
       accelY = (double)intAccelY/255.0;
       accelZ = (double)intAccelZ/255.0; 
  }
