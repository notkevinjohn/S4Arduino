/** Librarys of Code for the project **/
#include <S4.h>
#include <S4Sensor.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <WiFly.h>

S4 S4;
S4Sensor S4Sensor;

/****Sensor Variables ***/
double temperature;
long pressure;
double humidity;
double temperature2;
double accelX;
double accelY;
double accelZ;
int magX;
int magY;
int magZ;

void setup()
{
  Serial.begin(9600);
  S4.useWiFi(true);
  S4.useGPS(true);
  S4.useTCP(false);
  S4.begin("Stratos","Telemetry");
  S4Sensor.startBarometric();
  S4Sensor.startHumidity();
  S4Sensor.startAccelerometer();
  S4Sensor.startMagnetometer();
}

void loop()
{
   S4Sensor.getBarometric(pressure,temperature); 
   S4Sensor.getHumidity(humidity,temperature2);
   S4Sensor.getAccelerometer(accelX,accelY,accelZ);
   S4Sensor.getMagnetometer(magX,magY,magZ);

   S4.addData("Baro",pressure);
   S4.addData("Temp",temperature,2);
   S4.addData("Hum", humidity,2);
   S4.addData("Temp2",temperature2,2);
   S4.addData("AcelX",accelX,4);
   S4.addData("AcelY",accelY,4);
   S4.addData("AcelZ",accelZ,4);
   S4.addData("MagX",magX);
   S4.addData("MagY",magY);
   S4.addData("MagZ",magZ);
   
   S4.writeData();
 }
