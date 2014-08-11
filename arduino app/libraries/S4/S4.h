/*
  S4.h - Library for the overall S4 Program
  Kevin Zack
  Sonoma State University
  NASA E/PO
  Released into the public domain.
*/
  #ifndef S4_h
  #define S4_h
  #include "Arduino.h"

  class S4
  {
        public:
               S4();
               void begin(char* DeviceName, char* RouterName);
               bool WiFiHankshake(char* DeviceName);
               void useGPS(bool setUseGPS);
               void useTCP(bool setUseTCP);
               void useWiFi(bool statement);
               void writeData();
               void addData(char* key, int value);
               void addData(char* key, double value,int precision);
               void addData(char* key, char* value);
               void addData(char* key, long value);
               void addData(char* key, unsigned int value);
               void join(const char* ssid);
        private:
                
  };
  #endif
