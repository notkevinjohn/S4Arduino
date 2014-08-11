 /*
  HIH6130.cpp - Library for the Sensors Supported by S4
  Kevin Zack
  Sonoma State University
  NASA E/PO
  Released into the public domain.
*/
  #include "HIH6130.h"
  #include "Arduino.h"
  #include "Wire.h"
 #define addressHum 0x27
 
  HIH6130::HIH6130()
  {
  }
 
 byte HIH6130::getHumidity(double &humidity, double &temperature)
  {
      byte Hum_H, Hum_L, Temp_H, Temp_L, _status;
      unsigned int H_dat, T_dat;
      
      Wire.beginTransmission(addressHum); 
      Wire.endTransmission();
      
      Wire.requestFrom((int)addressHum, (int) 4);
      Hum_H = Wire.read();
      Hum_L = Wire.read();
      Temp_H = Wire.read();
      Temp_L = Wire.read();
      Wire.endTransmission();
      
      _status = (Hum_H >> 6) & 0x03;
      Hum_H = Hum_H & 0x3f;
      H_dat = (((unsigned int)Hum_H) << 8) | Hum_L;
      T_dat = (((unsigned int)Temp_H) << 8) | Temp_L;
      
      
      T_dat = T_dat / 4;
      humidity = (double) H_dat * 6.10e-3;
      temperature = (double)T_dat *1.007e-2-40.0;
      return(_status);
  }
