#include <ESP8266WiFi.h>

WiFiClient client;
WiFiServer server(80);
#define led D4

void setup() 
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  WiFi.begin("iot", "project1234");
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.println(WiFi.localIP());
  server.begin(); 
  Serial.println("Server started"); 
}

void loop() 
{
  client = server.available();  //Gets a client that is connected to the server and has data available for reading.    
  if (client == 1)
  {  
    String request =  client.readStringUntil('\n');
    Serial.println(request);
    request.trim();
    if(request == "GET /ledon HTTP/1.1")
    {
      digitalWrite(led, HIGH);
    }
    if(request == "GET /ledoff HTTP/1.1")
    {
      digitalWrite(led, LOW);
    }
    /*if(request == "GET /led2on HTTP/1.1")
    {
      digitalWrite(led2, HIGH);
    }
    if(request == "GET /led2off HTTP/1.1")
    {
      digitalWrite(led2, LOW);
    }*/
  }
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<h1>Welcome to the Webpage!</h1>");
  client.println("<h3>LED Controls<h3>");
  client.println("<br>");
  client.println("<a href=\"/ledon\"\"><button>LED  ON</button></a>");
  client.println("<a href=\"/ledoff\"\"><button>LED OFF</button></a><br/>");
  
 /* client.println("<a href=\"/led2on\"\"><button>LED 2 ON</button></a>");
  client.println("<a href=\"/led2off\"\"><button>LED 2 OFF</button></a><br/>");*/
  client.println("</html>");
}
