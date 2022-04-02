#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
const int LM35 = A0;
//----------- Enter you Wi-Fi Details---------//
char ssid[] = "POCO X2"; //SSID
char pass[] = "23456789"; // Password
//-------------------------------------------//

WiFiClient  client;

unsigned long myChannelNumber = 1692760; // Channel ID here
const int FieldNumber = 1;
const char * myWriteAPIKey = "BRPZTFXC51XRL9D0"; 
// Your Write API Key here3

void setup()
{
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}
void loop()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(ssid, pass);
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nConnected.");
  }
  int ADC;
  float temp;
  ADC = analogRead(LM35);  /* Read Temperature */
  temp = (ADC * 3); /* Convert adc value to equivalent voltage */
  temp = (temp / 10); /* LM35 gives output of 10mv/°C */
  Serial.print("Temperature = ");
  Serial.print(temp);
  Serial.println(" *C");
  delay(100);
  ThingSpeak.writeField(myChannelNumber, FieldNumber,temp+20, myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber,2, 40, myWriteAPIKey);
  delay(100);
}
