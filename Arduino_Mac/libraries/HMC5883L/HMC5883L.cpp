 /*
  HMC5883L.cpp - Library for the Sensors Supported by S4
  Kevin Zack
  Sonoma State University
  NASA E/PO
  Released into the public domain.
*/
  #include "Arduino.h"
  #include "HMC5883L.h"
  #include "Wire.h"
  
 #define addressMag  0x1E


  HMC5883L::HMC5883L()
  {
  }
  
  void HMC5883L::init()
  {
      Wire.beginTransmission(addressMag); //open communication with HMC5883
      Wire.write(0x02); //select mode register
      Wire.write(0x00); //continuous measurement mode
      Wire.endTransmission();
  }
  
  void HMC5883L::getMagnetometer(int &magX, int &magY, int &magZ)
  {
       
      Wire.beginTransmission(addressMag);
      Wire.write(0x03); //select register 3, X MSB register
      Wire.endTransmission();
      
      Wire.requestFrom(addressMag, 6);
      if(6<=Wire.available())
      {
          magX = Wire.read()<<8; //X msb
          magX |= Wire.read(); //X lsb
          magZ = Wire.read()<<8; //Z msb
          magZ |= Wire.read(); //Z lsb
          magY = Wire.read()<<8; //Y msb
          magY |= Wire.read(); //Y lsb
      }
   }
               
