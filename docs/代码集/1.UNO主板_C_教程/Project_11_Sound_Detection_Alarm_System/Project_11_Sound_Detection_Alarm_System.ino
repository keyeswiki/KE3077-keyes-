//**********************************************************************************
/*  
 * 名称   : Sound_Detection_Alarm_System
 * 功能   : 声音传感器控制LED和蜂鸣器
 * 作者   : http://www.keyes-robot.com/ 
*/
int item = 0;  //设置item为0

void setup() {
  Serial.begin(9600); //设置串口波特率为9600
  pinMode(A0, INPUT);  //声音传感器连接A0上，并设置为输入模式
  pinMode(4, OUTPUT); //将有源蜂鸣器连接到D4上，并设置为输出模式
  pinMode(5, OUTPUT);  //将LED连接到D5上，并设置为输出模式
}

void loop() {
  item = analogRead(A0);    //读取传感器的模拟信号
  Serial.println(item);  //串口打印传感器输出的声音大小模拟信号
  if (item > 300) {  //模拟值大于300
    digitalWrite(4, HIGH); //打开蜂鸣器
    digitalWrite(5, HIGH);  //打开LED
    delay(500);  //延迟 500ms
    digitalWrite(4, LOW);  //关闭蜂鸣器
    digitalWrite(5, LOW);  //关闭LED
    delay(500);  //延迟 500ms
  } else {  //模拟值小于等于300
    digitalWrite(4, LOW); //关闭蜂鸣器
    digitalWrite(5, LOW);  //关闭LED
  }
}
//**********************************************************************************