/** Librarys of Code for the project **/
#include <S4.h>
#include <S4Sensor.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <WiFly.h>

S4Sensor S4Sensor;

/****Sensor Variables ***/
double temperature;
long pressure;

void setup()
{
  Serial.begin(9600);
  S4Sensor.startBarometric();
}
void loop()
{
  S4Sensor.getBarometric(pressure,temperature); 
  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.print(" Pascals      Temperature: ");
  Serial.print(temperature);
  Serial.println(" degrees Celsius");
  delay(500);
}

