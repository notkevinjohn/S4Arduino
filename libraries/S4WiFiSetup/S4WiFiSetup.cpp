/*
  S4WiFiSetup.cpp - Library for setting up the wifi shield
  Kevin Zack
  Sonoma State University
  NASA E/PO
  Released into the public domain.
*/


// NEEED TO SET WIFIDEVICE TO PUBLIC NOT PRIVATE FUNCTIONS!!!!

  #include "Arduino.h"
  #include "WiFly.h"
  #include "S4WiFiSetup.h"
  #include "WiFlyDevice.h"
  /*
  const char* deviceName = "Payload";
  const char* ipAddress = "192.168.1.3";
  const char* ssid = "DeviceTesting";
  const char* hostAddress = "192.168.2";
  const char* port = "2000";
  const char* brodcastAddress = hostAddress;
  const char* seconds = "0x01";
  const char* auth = "1";
  const char* routerKey = "ac8afe4e5fb3931264f5df2f6f";
  const char* isExtAnt = "1";
  const char* value = "0";
  const char* gateway = "192.168.1.1";
  const char* rate = "0";
  const char* size = "1420";
  const char* proto = "1";
  const char* channel = "0";
*/

   S4WiFiSetup::S4WiFiSetup()
  {
           
  }
   void S4WiFiSetup::begin()
   {
     
      WiFly.uart.begin();
      WiFly.reboot();     
      Serial.print("Setup");
      WiFly.requireFlowControl();
      WiFly.enterCommandMode();  
      delay(100);   
   }
    void S4WiFiSetup::wifiConfig(const char* deviceName ,const char* ipAddress, const char* ssid,
                                 const char* hostAddress, const char* port, const char* brodcastAddress,
                                 const char* seconds,const char* auth,const char* routerKey,
                                 const char* isExtAnt,const char* value, const char* gateway,
                                 const char* rate, const char*,const char* proto,const char* channel)
    {
                                 
    }

   void S4WiFiSetup::setDCHP(const char* value)
   {
       WiFly.sendCommand("set ip dchp ",true,"");
       WiFly.sendCommand(value,true,"");
       WiFly.sendCommand("\r",true,"AOK");  
      delay(100);   
   }
   void S4WiFiSetup::setIpGateway(const char* gateway)
   {
       WiFly.sendCommand("set ip gateway ",true,"");
       WiFly.sendCommand(gateway,true,"");
       WiFly.sendCommand("\r",true,"AOK");  
      delay(100);   
   }
   void S4WiFiSetup::setLocalPort(const char* port)
   {
       WiFly.sendCommand("set ip localport ",true,"");
       WiFly.sendCommand(port,true,"");
       WiFly.sendCommand("\r",true,"AOK");   
      delay(100);           
   }
   void S4WiFiSetup::setWlanAuth(const char* auth)
   {
       WiFly.sendCommand("set wlan auth ",true,"");
       WiFly.sendCommand(auth,true,"");
       WiFly.sendCommand("\r",true,"AOK");  
      delay(100);              
   }
   void S4WiFiSetup::setDataRate(const char* rate)
   {
       WiFly.sendCommand("set wlan rate ",true,"");
       WiFly.sendCommand(rate,true,"");
       WiFly.sendCommand("\r",true,"AOK");  
      delay(100);                  
   }
   void S4WiFiSetup::setDeviceName(const char* deviceName)
   {
       WiFly.sendCommand("set opt deviceid ",true,"");
       WiFly.sendCommand(deviceName,true,"");
       WiFly.sendCommand("\r",true,"AOK");   
      delay(100);                  
   }
   void S4WiFiSetup::setRouterKey(const char* routerKey)
   {
       WiFly.sendCommand("set wlan key ",true,"");
       WiFly.sendCommand(routerKey,true,"");
       WiFly.sendCommand("\r",true,"AOK");   
      delay(100);                   
   }
   void S4WiFiSetup::setIpAddress(const char* ipAddress)
   {
       WiFly.sendCommand("set ip address ",true,"");
       WiFly.sendCommand(ipAddress,true,"");
       WiFly.sendCommand("\r",true,"AOK");   
      delay(100);                   
   }
   void S4WiFiSetup::setHostAdderss(const char* hostAddress)
   {
       WiFly.sendCommand("set ip host ",true,"");
       WiFly.sendCommand(hostAddress,true,"");
       WiFly.sendCommand("\r",true,"AOK");    
      delay(100);                 
   }
   void S4WiFiSetup::setHostPort(const char* hostPort)
   {
       WiFly.sendCommand("set ip remote ",true,"");
       WiFly.sendCommand(hostPort,true,"");
       WiFly.sendCommand("\r",true,"AOK");    
      delay(100);   
   }
    void S4WiFiSetup::setSSID(const char* ssid)
   {
       WiFly.sendCommand("set wlan ssid ",true,"");
       WiFly.sendCommand(ssid,true,"");
       WiFly.sendCommand("\r",true,"AOK");    
      delay(100);                 
   }
   void S4WiFiSetup::setBrodcastAddress(const char* brodcastAddress)
   {
       WiFly.sendCommand("set broadcast address ",true,"");
       WiFly.sendCommand(brodcastAddress,true,"");
       WiFly.sendCommand("\r",true,"AOK");    
      delay(100);                  
   }
   void S4WiFiSetup::setBordcastInterval(const char* seconds)
   {
       WiFly.sendCommand("set broadcast interval ",true,"");
       WiFly.sendCommand(seconds,true,"");
       WiFly.sendCommand("\r",true,"AOK");  
      delay(100);                   
   }
   void S4WiFiSetup::setExternalAntenna(const char* isExtAnt)
   {
       WiFly.sendCommand("set wlan ext_antenna ",true,"");
       WiFly.sendCommand(isExtAnt,true,"");
       WiFly.sendCommand("\r",true,"AOK");  
      delay(100);                  
   }
   void S4WiFiSetup::setFlushSize(const char* size)
   {
       WiFly.sendCommand("set comm size ",true,"");
       WiFly.sendCommand(size,true,"");
       WiFly.sendCommand("\r",true,"AOK");  
      delay(100);                   
   }
   void S4WiFiSetup::setProto(const char* proto)
   {
       WiFly.sendCommand("set ip protocol ",true,"");
       WiFly.sendCommand(proto,true,"");
       WiFly.sendCommand("\r",true,"AOK");  
      delay(100);                   
   }
   void S4WiFiSetup::setChannel(const char* channel)
   {
       WiFly.sendCommand("set wlan channel ",true,"");
       WiFly.sendCommand(channel,true,"");
       WiFly.sendCommand("\r",true,"AOK");  
      delay(100);                   
   }
   void S4WiFiSetup::Join(const char* ssid)
   {   
       WiFly.uart.begin();
       WiFly.reboot(); // Reboot to get device into known state
       
       WiFly.enterCommandMode();
       Serial.print("joining ");
       Serial.println(ssid);
       WiFly.sendCommand("join ",true,"");
       WiFly.sendCommand(ssid,true,"");
       WiFly.sendCommand("\r",true,"");
       Serial.println("assocated");
    
       WiFly.sendCommand("open \r",true,"");
       WiFly.uart.println();
    
    
      delay(100);                   
   }
   void S4WiFiSetup::save()
   {
      WiFly.sendCommand("save\r",true,"");  
      delay(100);   
   }  
