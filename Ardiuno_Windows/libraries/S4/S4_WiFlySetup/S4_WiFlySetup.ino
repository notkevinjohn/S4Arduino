#include <S4WiFiSetup.h>
#include "WiFly.h"

S4WiFiSetup S4WiFiSetup;

const char *device_ip_address = "192.168.1.2";
const char *server_ip_address = "192.168.1.66";
const char *wep_key = "ac8afe4e5fb3931264f5df2f6f";

void setup() 
{
  Serial.begin(9600);

  S4WiFiSetup.begin(); // initiates 
  S4WiFiSetup.setDCHP("1"); // 0 turns off DCHP; 1 turns on DCHP
  S4WiFiSetup.setIpGateway("192.168.1.1"); // sets gateway ip addresss
  S4WiFiSetup.setLocalPort("2000"); // sets port of that device connects too
  S4WiFiSetup.setWlanAuth("0"); // sets to WEP-128 key
  S4WiFiSetup.setDataRate("0"); // lowest data rate 1 M/sS for max range
  S4WiFiSetup.setDeviceName("SSU-01"); // device ID
  S4WiFiSetup.setRouterKey(wep_key); // WEP key
  S4WiFiSetup.setIpAddress(device_ip_address); // ip address of devices
  S4WiFiSetup.setHostAdderss(server_ip_address);// ip of computer that recives TCP or UDP connection
  S4WiFiSetup.setHostPort("2002");
  S4WiFiSetup.setSSID("DeviceTesting");
  S4WiFiSetup.setBrodcastAddress(server_ip_address); // ip of computer that recives brodcast message
  S4WiFiSetup.setBordcastInterval("0x1"); // brodcast every 2 seconda minumum
  S4WiFiSetup.setExternalAntenna("1"); //external antennae 1, chip antenna 0
  S4WiFiSetup.setFlushSize("1420"); // largest size for best TCP so 1420bytes at 9600 buad
  S4WiFiSetup.setProto("3"); //TCP proto 1; UDP proto 0
  S4WiFiSetup.setChannel("0"); // scans for the channel if 0; else 1-13 fixed
  S4WiFiSetup.save();

}

void loop()
{
  while(SpiSerial.available() > 0) 
  {
     Serial.write(SpiSerial.read());
  }
   if(Serial.available()) 
   {
    SpiSerial.write(Serial.read());
   }
}

