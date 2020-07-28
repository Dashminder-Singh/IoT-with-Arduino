#include<ESP8266WiFi.h>
const int led=2;
const int doorsensor=5;
String uname="Redmi",pwd="vtbhyflx";
int doorstatus=0;
void wifi()
{
  Serial.println();
  Serial.print("Connecting to WiFi");
  WiFi.begin(uname,pwd);
    while(WiFi.status()!=WL_CONNECTED)
    {
    delay(500);
    Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi Connected");

    Serial.print("Use this URL to connect:");
    Serial.print("http://");
    Serial.print(WiFi.localIP());
    Serial.print("/");
}


void setup() 
{
  wifi();
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(doorsensor,INPUT_PULLUP);

}

void loop() 
{
    if(digitalRead(doorsensor)==HIGH)
    {
        if(doorstatus!=1)
      {
           doorstatus=1;
           digitalWrite(led,HIGH);
           Serial.println("DOOR OPEN");
      }
     else
     {
         if(doorstatus!=0)
        {
        doorstatus=0;
        digitalWrite(led,LOW);
        Serial.println("DOOR CLOSED");
        }
      }
  }

}
