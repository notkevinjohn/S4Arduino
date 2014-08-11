/** Librarys of Code for the project **/
#include <S4GPS.h>
#include <SoftwareSerial.h>

/****Sensor Variables ***/
#define BUFFSIZE 90
char gps[BUFFSIZE]; // variable to store the gps data

S4GPS S4GPS; 
void setup()
{
  Serial.begin(9600);
  S4GPS.begin(9600); // initiate the GPS
}

void loop()
{
  if(S4GPS.getGPS(gps)) // wait until we get GPS data
  {
     Serial.println(gps); // print the gps data
  }
}
