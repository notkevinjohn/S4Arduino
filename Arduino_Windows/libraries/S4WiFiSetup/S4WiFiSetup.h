/*
  S4WiFiSetup.h - Library for setting up the wifi shield
  Kevin Zack
  Sonoma State University
  NASA E/PO
  Released into the public domain.
  
  To use this libary the WiFiDevive.h needs to set functions to public
*/
  #ifndef S4WiFiSetup_h
  #define S4WiFiSetup_h
  #include "Arduino.h"
  #include "WiFly.h"
  
  
   class S4WiFiSetup
  {
        public:
               S4WiFiSetup();
               void begin();
               void setDCHP(const char* value);
               void setIpGateway(const char* gateway);
               void setLocalPort(const char* port);
               void setWlanAuth(const char* auth);
               void setDataRate(const char* rate);
               void setDeviceName(const char* deviceName);
               void setRouterKey(const char* routerKey);
               void setIpAddress(const char* ipAddress);
               void setHostAdderss(const char* hostAddress);
               void setHostPort(const char* hostPort);
               void setBrodcastAddress(const char* brodcastAddress);
               void setBordcastInterval(const char* seconds);
               void setExternalAntenna(const char* isExtAnt);
               void setFlushSize(const char* size);
               void setProto(const char* proto);
               void setChannel(const char* channel);
               void setSSID(const char* ssid);
               void Join(const char* ssid);
               void save();
               
               void wifiConfig(const char* deviceName ,const char* ipAddress, const char* ssid,
                               const char* hostAddress, const char* port, const char* brodcastAddress,
                               const char* seconds,const char* auth,const char* routerKey,
                               const char* isExtAnt,const char* value, const char* gateway,
                               const char* rate, const char*,const char* proto,const char* channel);
        private:
                
  };
  #endif
