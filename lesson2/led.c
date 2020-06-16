void setup()
{
  int i=0;
  for(i=0;i<8;i++)
  {
 	 pinMode(i, OUTPUT);
  }
  
  
  
}

void loop()
{
  int i=0;
  for(i=0;i<8;i++)
  {
 	 digitalWrite(i, HIGH);
  	 delay(300); // Wait for 1000 millisecond(s)
 	 digitalWrite(i, LOW);
  	 delay(300); // Wait for 1000 millise8,i++cond(s)
  }
  for(i=7;i>=0;i--)
  {
 	 digitalWrite(i, HIGH);
  	 delay(300); // Wait for 1000 millisecond(s)
 	 digitalWrite(i, LOW);
  	 delay(300); // Wait for 1000 millise8,i++cond(s)
  }
  for(i=0;i<8;i++)
  {
 	 digitalWrite(i, HIGH);
     digitalWrite(i+2, HIGH);
     digitalWrite(i+4, HIGH);
     digitalWrite(i+6, HIGH);
  	 delay(400); // Wait for 1000 millisecond(s)
 	 digitalWrite(i, LOW);
     digitalWrite(i+2, LOW);
     digitalWrite(i+4, LOW);
     digitalWrite(i+6, LOW);
  	 delay(400); // Wait for 1000 millise8,i++cond(s)
  }
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  delay(600); // Wait for 1000 millisecond(s)
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  delay(600); // Wait for 1000 millisecond(s)
}