
int pir=10;
int store=0;


void setup() 
{
  
  pinMode(pir,INPUT);
  Serial.begin(9600);

}

void loop() 
{
  store=digitalRead(pir);
  Serial.println(store);
  

  

}
