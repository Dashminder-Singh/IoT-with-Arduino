int led1=10;
int sensorpin=A0;
int store=0;

void setup() 
{
 pinMode(led1,OUTPUT);
Serial.begin(9600);
}

void loop() 
  {
    store=analogRead(sensorpin);
    digitalWrite(led1,HIGH);
    delay(store);
    digitalWrite(led1,LOW);
    delay(store);
    Serial.println(store);
  }
