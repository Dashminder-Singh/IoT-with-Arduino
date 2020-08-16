#include<ESP8266WiFi.h>

void setup() 
{
  Serial.begin(9600);
  WiFi.begin("SSID","PWD");  
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(200);
  }
  Serial.println();
  Serial.println("Node MCU is Connected!");
  
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.println(WiFi.localIP());
}

void loop() 
{
  

}
