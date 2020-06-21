#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

#define S1 8
#define S2 9
#define S3 10
#define S4 11

#define LT 6
#define BT 7
void setup()
{
  pinMode(IN1, OUTPUT);//输入1
  pinMode(IN2, OUTPUT);//输入2
  pinMode(IN3, OUTPUT);//输入3
  pinMode(IN4, OUTPUT);//输入4
  pinMode(S1, OUTPUT);//片选1
  pinMode(S2, OUTPUT);//片选2
  pinMode(S3, OUTPUT);//片选3
  pinMode(S4, OUTPUT);//片选4
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  
  pinMode(LT,OUTPUT);//测试
  pinMode(BT,OUTPUT);//消隐
  
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  
 
}
int i=0;
byte income[3]={0};
void loop()
{
  if(Serial.available()>0)
  {
    
   income[0]=Serial.read();
   income[0]=income[0]-'0';
    
   digitalWrite(S1,LOW);
   digitalWrite(IN1,income[0]&0x1);
   digitalWrite(IN2,(income[0]>>1)&0x1);
   digitalWrite(IN3,(income[0]>>2)&0x1);
   digitalWrite(IN4,(income[0]>>3)&0x1);
   digitalWrite(S1,HIGH);
   delay(10);
    
   income[1]=Serial.read();
   income[1]=income[1]-'0';
   digitalWrite(S2,LOW);
   digitalWrite(IN1,income[1]&0x1);
   digitalWrite(IN2,(income[1]>>1)&0x1);
   digitalWrite(IN3,(income[1]>>2)&0x1);
   digitalWrite(IN4,(income[1]>>3)&0x1);
   digitalWrite(S2,HIGH);
   delay(10);
   
   income[2]=Serial.read();
   income[2]=income[2]-'0';
   digitalWrite(S3,LOW);
   digitalWrite(IN1,income[2]&0x1);
   digitalWrite(IN2,(income[2]>>1)&0x1);
   digitalWrite(IN3,(income[2]>>2)&0x1);
   digitalWrite(IN4,(income[2]>>3)&0x1);
   digitalWrite(S3,HIGH);
   delay(10);
   
   income[3]=Serial.read();
   income[3]=income[3]-'0';
   digitalWrite(S4,LOW);
   digitalWrite(IN1,income[3]&0x1);
   digitalWrite(IN2,(income[3]>>1)&0x1);
   digitalWrite(IN3,(income[3]>>2)&0x1);
   digitalWrite(IN4,(income[3]>>3)&0x1);
   digitalWrite(S4,HIGH);
   delay(10);
  }
}

