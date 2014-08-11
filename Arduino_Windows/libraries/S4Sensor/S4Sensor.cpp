/*
  S4Sensor.cpp - Library for the Sensors Supported by S4
  Kevin Zack
  Sonoma State University
  NASA E/PO
  Released into the public domain.
*/
  #include "S4Sensor.h"
  #include "Arduino.h"
  #include "S4.h"
  #include "WiFly.h"

  
  #include "Wire.h"

  #include "SoftwareSerial.h"
  
  #include "../BMP085/BMP085.h"
  #include "../BMP085/BMP085.cpp"
  
  #include "../HMC5883L/HMC5883L.h"
  #include "../HMC5883L/HMC5883L.cpp"
  
  #include "../HIH6130/HIH6130.h"
  #include "../HIH6130/HIH6130.cpp"
  
  #include "../S4Accelerometer/S4Accelerometer.h"
  #include "../S4Accelerometer/S4Accelerometer.cpp"


  BMP085 presSen;
  HIH6130 hum;
  HMC5883L mag;
  S4Accelerometer accel;

  
  S4Sensor::S4Sensor()
  {   
      
  }
  void S4Sensor::startBarometric()
  {
       presSen.init();
  }
       
  void S4Sensor::getBarometric(long & pressure, double &temperature)
  {
       long temp;
       presSen.getPressure(&pressure);
       presSen.getTemperature(&temp);
       temperature = (double)temp/10.0;
       
  }
  void S4Sensor::startHumidity()
  {
       
  }
  
  byte S4Sensor::getHumidity(double &humidity, double &temperature)
  {
       hum.getHumidity(humidity, temperature);
  }

  void S4Sensor::startAccelerometer()
  {
       accel.init(1,1, 1, 10, 255);
  }
  void S4Sensor::getAccelerometer(double &accelX, double &accelY, double &accelZ)
  {
       accel.getAccel(accelX,accelY,accelZ);       
  }
  void S4Sensor::startMagnetometer()
  {    
       mag.init();
  }
  void S4Sensor::getMagnetometer(int &x, int &y, int &z)
  {
       mag.getMagnetometer(x,y,z);
  }
