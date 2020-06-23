int pinInterrupt=2;
int tick = 0; //计数值
volatile byte x=0;

//中断服务程序
void myfunc()
{
  Serial.print("Number: ");
  Serial.println(tick++);
  for(x=0;x<=9;x++)
  {
    digitalWrite(3,x&0x1);
    digitalWrite(4,(x>>1)&0x1);
    digitalWrite(5,(x>>2)&0x1);
    digitalWrite(6,(x>>3)&0x1);
    
    delayMicroseconds(1000);
  }

  
}
 
void setup()
{
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  Serial.begin(9600); //初始化串口
  attachInterrupt( digitalPinToInterrupt(pinInterrupt), myfunc, CHANGE);
}
byte i=0;
void loop()
{
  
  for(i=0;i<=9;i++)
  {
    digitalWrite(3,i&0x1);
    digitalWrite(4,(i>>1)&0x1);
    digitalWrite(5,(i>>2)&0x1);
    digitalWrite(6,(i>>3)&0x1);
  	delay(1000);
  }
  if(digitalRead(2) == LOW||digitalRead(2) ==HIGH)
  {
    for(x=0;x<=9;x++)
  	{
    	digitalWrite(3,x&0x1);
    	digitalWrite(4,(x>>1)&0x1);
    	digitalWrite(5,(x>>2)&0x1);
    	digitalWrite(6,(x>>3)&0x1);
    
    	delay(1000);
  	}
  }
}


 
