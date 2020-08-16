#include<ESP8266WiFi.h>
WiFiClient Client;
WiFiServer Server(80);

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
  Client=Server.available();   //gets a client that is connected to the server & has data is available for reading
  if(Client==1) //intially zero,client have some data-request
  {
    String request=Client.readStringUntil('\n'); //full read,until his finished the line
    Serial.println(request);
  }

}
