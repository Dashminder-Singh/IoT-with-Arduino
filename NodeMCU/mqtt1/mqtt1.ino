#include <ESP8266WiFi.h>
#include <PubSubClient.h>
void setup_wifi();
void callback(char* topic, byte* payload, unsigned int length);
void reconnect();

const char* ssid = "Xiaomi";
const char* password = "vtbhyflx";

const char* mqtt_server = "mqtt.eclipse.org";
int led_pin = 2;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() 
{
    pinMode(led_pin, OUTPUT);

    Serial.begin(9600);
    setup_wifi();
    client.setServer(mqtt_server, 1883);
    client.setCallback(callback);
    reconnect();
}

void setup_wifi(){

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) 
{
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) 
  {
    Serial.print((char)payload[i]);
  }
  
  if((char)payload[0] == '1') 
  { //on
     digitalWrite(led_pin, LOW);
     Serial.print("pin high");
  }   
  else if((char)payload[0] == '0' ) //off
  {  digitalWrite(led_pin, HIGH);
     Serial.print("pin low");
  }
  Serial.println();
}

void reconnect() {
  
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    
    if (client.connect("NIELITPJ125")) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("Class/light1", "1");
      // ... and resubscribe
      client.subscribe("Class/light1");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void loop() {
 
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
