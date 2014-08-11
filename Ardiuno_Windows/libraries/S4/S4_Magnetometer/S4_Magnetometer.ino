/** Librarys of Code for the project **/
#include <S4.h>
#include <S4Sensor.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <WiFly.h>

S4Sensor S4Sensor;
/*Note the readout returns 10x microTesla
/****Sensor Variables ***/
int magX;
int magY;
int magZ;

void setup()
{
  Serial.begin(9600);
  S4Sensor.startMagnetometer(); // initiate the Magnetometer
  Serial.println('start');
}
void loop()
{
  S4Sensor.getMagnetometer(magX,magY,magZ); // fill the variables with new data
  Serial.print("Mag X: ");
  Serial.print(magX);
  Serial.print("  x10^-5 Tesla   Mag Y: ");
  Serial.print(magY);
  Serial.print("  x10^-5 Tesla   Mag Z: ");
  Serial.print(magZ);
  Serial.println("  x10^-5 Tesla");
  delay(1000); // delay 1000 ms
}

