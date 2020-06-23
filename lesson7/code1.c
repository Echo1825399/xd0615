void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}
byte i=0;
void loop()
{
  for(i=0;i<=9;i++)
  {
    digitalWrite(2,i&0x1);
    digitalWrite(3,(i>>1)&0x1);
    digitalWrite(4,(i>>2)&0x1);
    digitalWrite(5,(i>>3)&0x1);
  	delay(1000);
  }
}
