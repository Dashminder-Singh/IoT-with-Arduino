int sensorpin=A0;
int value=0;
void setup() 
{
  Serial.begin(9600);

}

void loop() 
{
  sensorpin=analogRead(value);
  Serial.print(" AirQua ");
  Serial.print(sensorpin,DEC);
  Serial.println(" PPM ");
  
  delay(500);

}
