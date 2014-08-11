/** Librarys of Code for the project **/
#include <S4.h>
#include <S4Sensor.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <WiFly.h>

S4 S4;

void setup()
{
  Serial.begin(9600);
  S4.useWiFi(true);
  S4.useGPS(false);
  S4.begin("PayloadName","DeviceTesting"); 
}

void loop()
{
   long data = 1;
   S4.addData("data",data);  
   S4.writeData();
   delay(1000);
 }
