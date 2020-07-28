#include <ESP8266WiFi.h>
int ledPin=2;
WiFiServer server(80);

void setup() {
  pinMode(ledPin,OUTPUT); 
  Serial.begin(9600);
  Serial.println();
  Serial.print("Connecting to WiFi ");
  
  WiFi.begin("Xiaomi" , "vtbhyflx");

  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  server.begin();
  Serial.println("Server started");
}

void loop() 
{
  WiFiClient client = server.available();
  if (!client) { 
    return;
  }
    Serial.println("new client");
    while(!client.available())
    {
    delay(1);
    }
  
   
 
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
   

 
  int value = LOW;
  if (request.indexOf("/LED=ON") != -1) {
    digitalWrite(ledPin, LOW);
    value = HIGH;
  } 
  if (request.indexOf("/LED=OFF") != -1){
    digitalWrite(ledPin, HIGH);
    value = LOW;
  }
 
   // Return the response in form HTML page
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
   
  client.print("Led pin is now: ");
   
  if(value == HIGH) {
    client.print("On");  
  } else {
    client.print("Off");
  }
  client.println("<br><h1> Welcome to NIELIT </h1><hr><br>");
  //if (value == LOW){ 
      client.println("Click <a href=\"/LED=ON\">here on</a> turn the LED ON<br>");
  //}else {
      client.println("Click <a href=\"/LED=OFF\"> here Off</a> turn the LED OFF <br>");
     
  //}
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
  
 
}
