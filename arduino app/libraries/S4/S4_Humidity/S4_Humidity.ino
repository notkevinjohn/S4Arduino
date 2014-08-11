/** Librarys of Code for the project **/
#include <S4.h>
#include <S4Sensor.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <WiFly.h>


S4Sensor S4Sensor;

/****Sensor Variables ***/
double humidity;
double temperature;

void setup()
{
  Serial.begin(9600);
  S4Sensor.startHumidity();// initiate the Humidity detector
}
void loop()
{
  S4Sensor.getHumidity(humidity,temperature); // fill the variables with new data
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" relative %   Temperature: ");
  Serial.print(temperature);
  Serial.println(" degrees Celsius");
  delay(500); // delay 500 ms (0.5 seconds)
}

