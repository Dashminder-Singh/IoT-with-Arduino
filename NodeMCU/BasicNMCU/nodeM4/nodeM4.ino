#include<ESP8266WiFi.h>
WiFiClient Client;
WiFiServer Server(80);
#define led D4        //led on/off
void setup() 
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  WiFi.softAP("NodeMCU", "123456");
  Serial.println();
  Serial.println(WiFi.softAPIP());
  Server.begin();  //NMCU as server
} 
void loop() 
{
  Client=Server.available();   //gets a client that is connected to the server & has data is available for reading
  if(Client==1) //intially zero,client have some data-request
  {
    String request=Client.readStringUntil('\n'); //full read,until his finished the line
    Serial.println(request);
    request.trim();  //clear the garbage values
    
    if(request== "GET/ledon HTTP/1.1")
    {
      digitalWrite(led,HIGH);
    }
    if(request== "GET/ledoff HTTP/1.1")
    {
      digitalWrite(led,LOW);
    }
  }
}
