/*
   超声波测距仪
   测距仪并将距离返回到范围内最接近的对象。为此，它会发送一个
   向传感器发送脉冲以启动读数，然后
   监听返回的脉冲，长度返回脉冲与物体与传感器的距离。

   电路：
    * 超声波距离传感器的正极连接连接到arduino板的+5V
    * GND连接到地面
    * SIG（signal信号）连接已连接到数字引脚7
*/

int inches = 0;   //定义变量inches，表示物体与传感器的距离，单位为英寸

int cm = 0;       //同样表示物体与传感器之间的距离，但单位为厘米

long readUltrasonicDistance(int triggerPin, int echoPin)    // 创建变量存储脉冲宽度和距离

{
  
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // 超声波测距传感器的测距过程可以通过一个2毫秒或以上的脉冲来触发。
  //引脚先输出低电平，再输出2ms的高电平然后再拉低，就产生了2ms的脉冲，用普通引脚进行数字操作
  // 先拉低，确保脉冲明显
  
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW); 			//产生10ms的脉冲
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);		
  //需要测量脉宽，它的长度就是声音传播的时间，单位为微秒
}

void setup()
{
  Serial.begin(9600);   //初始化串口

}


void loop()
{
  // measure the ping time in cm
  cm = 0.01723 * readUltrasonicDistance(7, 7);  
  //声音传播速度大约是340m/s,则1微秒的路程是0.034cm，再除以2，声音走了两遍
  // convert to inches by dividing by 2.54
  inches = (cm / 2.54);   //距离厘米转化为英寸，一英寸大约相当于2.54cm
  Serial.print(inches);   //打印出距离（以英寸为单位）
  Serial.print("in, ");
  Serial.print(cm);       //打印出距离，为厘米为单位
  Serial.println("cm");
  delay(100); // Wait for 100 millisecond(s)
}