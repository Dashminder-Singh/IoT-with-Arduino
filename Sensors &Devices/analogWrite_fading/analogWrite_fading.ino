int led1 =10,led2=6,led3=9,led4=11; 
void setup()
{
  pinMode(led1, OUTPUT); 
  Serial.begin(9600);
}

void loop() 
{
  for (int i=0; i<=255; i+=10)
  {   
      analogWrite(led1, i);
      Serial.println(i);
       delay(300);
  } for (int i=255; i>=0; i-=10)
      {
      analogWrite(led1,500-i);
      Serial.println(i);
      delay(300);
      }
  }
