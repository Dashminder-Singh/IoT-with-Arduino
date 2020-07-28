#define sensorPin 12
int ledPin = 13;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
}

int sense1 = 0;
void loop()
{
  //  int senseValue = digitalRead(sensorPin);
  if (digitalRead(sensorPin) == HIGH)
  {
    if (sense1 == 1)
    {
      sense1 = 0;
    } else
    {
      sense1 = 1;
    }
    while (digitalRead(sensorPin) == HIGH);
  }
  if (sense1 == 1)
  {
    digitalWrite(ledPin, HIGH);
    Serial.println("TOUCHED");
  } else
  {
    digitalWrite(ledPin, LOW);
    Serial.println("not Touched");
  }

}
/*if (senseValue == HIGH){
    digitalWrite(ledPin, HIGH);
    Serial.println("TOUCHED");
  }
  else{
    digitalWrite(ledPin,LOW);
    Serial.println("not touched");
  }
  delay(500);*/
