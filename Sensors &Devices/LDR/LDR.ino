int led1=10;
int pin=A0;
int ldr=0;
void setup() 
{
  pinMode(led1,OUTPUT);
  Serial.begin(9600);
}
void loop() 
{
   ldr=analogRead(pin);
   if(ldr<=650)
   {
    digitalWrite(led1,HIGH);
   }
   else
   {
      digitalWrite(led1,LOW);
   }
    Serial.println(ldr);
    delay(100);
  } 
