/** Librarys of Code for the project **/
#include <S4.h>
#include <S4Sensor.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <WiFly.h>

S4Sensor S4Sensor;

/****Sensor Variables ***/
double accelX;
double accelY;
double accelZ;

void setup()
{
  Serial.begin(9600);
  S4Sensor.startAccelerometer(); // initiate the accelerometer
}
void loop()
{
  S4Sensor.getAccelerometer(accelX,accelY,accelZ); // fill the variables with new data
  Serial.print("Accel X: ");
  Serial.print(accelX);
  Serial.print("g  Accel Y: ");
  Serial.print(accelY);
  Serial.print("g   Accel Z: ");
  Serial.print(accelZ);
  Serial.println("g");
  delay(100); // delay 100 ms
}

