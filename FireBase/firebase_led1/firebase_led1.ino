
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "fir-led-9da44.firebaseio.com"
#define FIREBASE_AUTH "c1aXXUwknfpGIvQ9xKG1Xw2xS97qj9fO5xeIcKJO"
#define WIFI_SSID "Redmi"
#define WIFI_PASSWORD "vtbhyflx"

int ledpin=2;

void setup() 
{
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
// connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
  Serial.print(".");
  delay(500);
  }

Serial.println();
Serial.print("connected: ");
Serial.println(WiFi.localIP());
Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
Firebase.set("LED_STATUS", 0);
}

int n = 0;
void loop() 
{
// get value
n = Firebase.getInt("LED_STATUS");
// handle error
if (n==0) 
{

digitalWrite(ledpin,HIGH); 
Serial.println("LED OFF"); 
return;
delay(10);
}
else {
Serial.println("LED ON");
digitalWrite(ledpin,LOW);  
return;
}
}
