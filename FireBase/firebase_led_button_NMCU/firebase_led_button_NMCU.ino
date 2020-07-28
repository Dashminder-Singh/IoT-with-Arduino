#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "fir-led-9da44.firebaseio.com"
#define FIREBASE_AUTH "c1aXXUwknfpGIvQ9xKG1Xw2xS97qj9fO5xeIcKJO"
#define WIFI_SSID "Redmi"
#define WIFI_PASSWORD "    "


const int led1Pin =  D4, led2Pin =  D3;     // the number of the LED pin
//const int led1Addr = 100, led2Addr = 101;   // address in EEPROM for LED1 , LED2 status

const int led3Pin =  D2, led4Pin =  D1;     // the number of the LED pin
//const int led3Addr = 103, led4Addr = 104;   // address in EEPROM for LED1 , LED2 status

const int button1Pin = D5, button2Pin = D6;// the number of the pushbutton pin
const int button3Pin = D7, button4Pin = D8;// the number of the pushbutton pin

int btn1flag = 0, btn2flag = 0;
int btn3flag = 0, btn4flag = 0;

int button1State = 0, button2State = 0; // variable for button1State the pushbutton status
int button3State = 0, button4State = 0; // variable for button1State the pushbutton status

void setup() {
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);

  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, LOW);
  digitalWrite(led3Pin, LOW);
  digitalWrite(led4Pin, LOW);

  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
    digitalWrite(led4Pin, LOW);
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);


  //  Firebase.set("LED_STATUS", 0);
  //  Firebase.set("LED_STATUS2", 0);
  //  Firebase.set("LED_STATUS3", 0);
  //  Firebase.set("LED_STATUS4", 0);
}
void readEEPROMupdateLED();
void   updateLEDstatus();
int n = 0, n2 = 0, n3 = 0, n4 = 0;

void loop() {
  // set value
  n = Firebase.getInt("LED_STATUS");
  n2 = Firebase.getInt("LED_STATUS2");
  n3 = Firebase.getInt("LED_STATUS3");
  n4 = Firebase.getInt("LED_STATUS4");

  if (n == 1) {
    Serial.println("LED1 is ON");
    digitalWrite(led1Pin, HIGH);
  }
  if (n == 0) {
    Serial.println("LED1 is OFF");
    digitalWrite(led1Pin, LOW);
  }
  ///////LED 2 ///////

  if (n2 == 1) {
    Serial.println("LED2 is ON: ");
    digitalWrite(led2Pin, HIGH);
  }
  if (n2 == 0)  {
    Serial.println("LED2 is OFF");
    digitalWrite(led2Pin, LOW);
  }
  ///////LED 3///////
  if (n3 == 1) {
    Serial.println("LED3 is ON");
    digitalWrite(led3Pin, HIGH);

  }
  if (n3 == 0) {
    Serial.println("LED3 is OFF");
    digitalWrite(led3Pin, LOW);
  }
  ///////led4Pin///////
  if (n4 == 1) {
    Serial.println("LED4 is ON");
    digitalWrite(led4Pin, HIGH);

  }
  if (n4 == 0) {
    Serial.println("LED4 is OFF");
    digitalWrite(led4Pin, LOW);
  }

  if (Firebase.failed()) {
    Serial.print("setting /message failed:");
    Serial.println(Firebase.error());

  }
  Serial.println(" ");
}
