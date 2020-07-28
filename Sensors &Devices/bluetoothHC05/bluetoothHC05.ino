int led1=10,led2=6,led3=9,led4=11;
void setup() 
{
  pinMode(led1 ,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  Serial.begin(9600);
  Serial.println("Reading value from serial " ) ;
}
int val = 0;
void loop() 
{
  val = Serial.read();
  
  if (val!=-1)  
  {
    Serial.println(val);
 //   delay(500);
  }
  if (val==49)  
  { 
    digitalWrite(led1, HIGH);
  }
  if (val==50) 
  { 
    digitalWrite(led1, LOW);
  }
  if(val==51)
  {
    digitalWrite(led2,HIGH);
  }
  if(val==52)
  {
    digitalWrite(led2,LOW);
  }
  if(val==53)
  {
    digitalWrite(led3,HIGH);
  }
  if(val==54)
  {
    digitalWrite(led3,LOW);
  }
  if(val==55)
  {
    digitalWrite(led4,HIGH);
  }
  if(val==56)
  {
    digitalWrite(led4,LOW);
  }
  
}
  
