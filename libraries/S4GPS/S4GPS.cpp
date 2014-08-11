/*
  S4GPS.cpp - Library for reading the GPS 
  Kevin Zack
  Sonoma State University
  NASA E/PO
  Released into the public domain.
  */

  #include "Arduino.h"
  #include "S4GPS.h"
  #include "SoftwareSerial.h"

  #define RX 2
  #define TX 3
  
  #define useVTG 0
  #define useRMC 0
  #define useGSV 0
  #define useGSA 0
  #define useGLL 0
  

  #define BUFFSIZE 90
  uint8_t bufferidx = 0;
  uint8_t fix = 0; // current fix data
  uint8_t i;
  char buffer[BUFFSIZE];

  
  uint8_t remVTG[26] = {0xB5,0x62,0x06,0x01,0x08,0x00,0xF0,0x05,0x00,0x00,0x00,0x00,0x00,0x01,0x05,0x47,0xB5,0x62,0x06,0x01,0x02,0x00,0x0F0,0x05,0xFE,0x16};
  uint8_t remRMC[26] = {0xB5,0x62,0x06,0x01,0x08,0x00,0xF0,0x04,0x00,0x00,0x00,0x00,0x00,0x01,0x04,0x40,0xB5,0x62,0x06,0x01,0x02,0x00,0xF0,0x04,0x0FD,0x15}; 
  uint8_t remGSV[26] = {0xB5,0x62,0x06,0x01,0x08,0x00,0xF0,0x03,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x39,0xB5,0x62,0x06,0x01,0x02,0x00,0xF0,0x03,0xFC,0x14}; 
  uint8_t remGSA[26] = {0xB5,0x62,0x06,0x01,0x08,0x00,0xF0,0x02,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x32,0xB5,0x62,0x06,0x01,0x02,0x00,0xF0,0x02,0xFB,0x13}; 
  uint8_t remGLL[26] = {0xB5,0x62,0x06,0x01,0x08,0x00,0xF0,0x01,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x2B,0xB5,0x62,0x06,0x01,0x02,0x00,0xF0,0x01,0xFA,0x12};
  uint8_t setNAV[44] = {0xB5,0x62,0x06,0x03,0x1C,0x00,0x07,0x03,0x10,0x18,0x14,0x05,0x00,0x3C,0x3C,0x14,0xE8,0x03,0x00,0x00,0x00,0x17,0xFA,0x00,0xFA,0x00,0x64,0x00,0x2C,0x01,0x0F,0x00,0x00,0x00,0x92,0x70,0xB5,0x62,0x06,0x03,0x00,0x00,0x09,0x21};
  uint8_t setNAV2[56] = {0xB5,0x62,0x06,0x1A,0x28,0x00,0x07,0x00,0x00,0x00,0x03,0x04,0x10,0x02,0x50,0xC3,0x00,0x00,0x18,0x14,0x05,0x3C,0x00,0x03,0x00,0x00,0xFA,0x00,0xFA,0x00,0x64,0x00,0x2C,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x35,0xB5,0x62,0x06,0x1A,0x00,0x00,0x20,0x66};
  uint8_t setNAV5[52] = {0xB5,0x62,0x06,0x24,0x24,0x00,0xFF,0xFF,0x08,0x03,0x00,0x00,0x00,0x00,0x10,0x27,0x00,0x00,0x05,0x00,0xFA,0x00,0xFA,0x00,0x64,0x00,0x2C,0x01,0x00,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x54,0x2C,0xB5,0x62,0x06,0x24,0x00,0x00,0x2A,0x84};
  
  SoftwareSerial gpsSerial = SoftwareSerial(RX,TX);
  
  S4GPS::S4GPS()
  {   

  }
  
  void S4GPS::begin(int BaudRate)               
  {       
      gpsSerial.begin(BaudRate);
      Configure();
  }
  
  void S4GPS::Configure()
  { 
	   Serial.println("configuring WiFly");
		setupGPS(remVTG,26);
       setupGPS(remRMC,26);
       setupGPS(remGSV,26);
       setupGPS(remGSA,26);
       setupGPS(remGLL,26);
       setupGPS(setNAV,44);
       setupGPS(setNAV2,56);
       setupGPS(setNAV5,52);
  }
  
  void S4GPS::setupGPS(uint8_t* mesg, uint8_t bits)
  {
      //Serial.println();
      for(int i = 0; i< bits; i++)
      {
          gpsSerial.write(mesg[i]);
          //Serial.print(mesg[i]);
      }   
  }
  
  bool S4GPS::getGPS(char* gps)
  {
     char c;
     uint8_t sum;
     while (gpsSerial.available())  // this might break it.
     {
       c = gpsSerial.read();
          
       if (bufferidx == 0) 
       {
                     
          while (c != '$')
          {
             c = gpsSerial.read(); 
          }
       }
       buffer[bufferidx] = c;
       if (c == '\n') 
       {
         buffer[bufferidx-1] = '\0'; // delete end line
         buffer[bufferidx+1] = 0; // terminate it
         
         if (buffer[bufferidx-4] != '*') 
         {
           bufferidx = 0;
          // return;
         }
          
          sum = parseHex(buffer[bufferidx-3]) * 16;
          sum += parseHex(buffer[bufferidx-2]);

          for (i=1; i < (bufferidx-4); i++) 
          {
            sum ^= buffer[i];
          }
          if (sum != 0) 
          {
            bufferidx = 0;
          //  return;
          }
          
          
          bufferidx++;
      
      
          //Serial.print(buffer);
         for(int i = 0; i < 90; i++)
         {
           gps[i] = buffer[i];
           }
      
         
          bufferidx = 0;
          
          return true;
        }
        bufferidx++;
        if (bufferidx == BUFFSIZE-1) 
        {
          bufferidx = 0;
        }
      }

}
  
  
  uint8_t S4GPS::parseHex(char c)
  {
     if (c < '0')
     {
         return 0;
     }
     if (c <= '9')
     {
         return c - '0';
     }
     if (c < 'A')
     {
         return 0;
     }
     if (c <= 'F')
     {
         return (c - 'A')+10;
     }
   }
