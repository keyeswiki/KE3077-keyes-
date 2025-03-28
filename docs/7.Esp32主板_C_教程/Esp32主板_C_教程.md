# Esp32主板_C_教程

## 1. Esp32主板：

![Img](./media/W0.png)

---

### 1. 简介:

在我们开始学习keyes 声音检测套件之前，首先介绍keyes ESP32 主控板，它是所有项目的核心。

keyes ESP32 主控板是基于ESP-WROOM-32模块所设计的的迷你开发板。该开发板引出大部分I/O至两侧的2.54mm间距的排针，开发者可以根据自己的需求连接外设。使用开发板进行开发和调试时，两侧的标准排针可以让你的操作更加简洁方便。

ESP-WROOM-32模块是业内集成度领先的 WiFi + 蓝牙解决方案，外部元器件少于 10 个，它集成了天线开关、射频 balun、功率放大器、低噪放大器、过滤器和电源管理模块。同时，它也集成了天采用 TSMC 低功耗 40nm 技术，功耗性能和射频性能，安全可靠，易于扩展至各种应用。

---

### 2. 规格参数:

微控制器: ESP-WROOM-32模块

USB转串口芯片: CP2102-GMR

工作电压:	DC 5V

工作电流：80mA（平均）

供电电流：500mA（最小）

工作温度范围: -40°C ~ +85°C 

WiFi模式：Station/SoftAP/SoftAP+Station/P2P

WiFi协议：802.11 b/g/n/e/i（802.11n，速度高达 150 Mbps

WiFi频率范围：2.4 GHz ~ 2.5 GHz

蓝牙协议：符合蓝牙 v4.2 BR/EDR 和 BLE 标准

尺寸：55x26x13mm

重量：9.8g

---

### 3. 各个接口和主要元件说明:

![Img](./media/W1.png)

![Img](./media/W2.png)

---

### 4. 各个接口详细说明:

- IO23: VSPI MOSI/SPI MOSI
- IO22: Wire SCL
- TXD0: IO1/Serial TX
- RXD0: IO3/Serial RX
- IO21: Wire SDA
- IO19: VSPI MISO/SPI MISO
- IO18: VSPI SCK/SPI SCK
- IO5: VSPI SS/SPI SS
- IO4: ADC10/TOUCH0
- IO0: ADC11/TOUCH1
- IO2: ADC12/TOUCH2
- IO15: HSPI SS/ADC13/TOUCH3/TDO
- SD1: IO8/FLASH D1
- SD0: IO7/FLASH D0
- CLK: IO6/FLASH SCK
- CMD: IO11/FLASH CMD
- SD3: IO10/FLASH D3
- SD2: IO9/FLASH D2
- IO13: HSPI MOSI/ADC14/TOUCH4/TCK
- IO12: HSPI MISO/ADC15/TOUCH5/TDI
- IO14: HSPI SCK/ADC16/TOUCH6/TMS
- IO27: ADC17/TOUCH7
- IO26: ADC19/DAC2
- IO25: ADC18/DAC1
- IO33: ADC5/TOUCH8
- IO32: ADC4/TOUCH9
- IO35: ADC7
- IO34: ADC6
- SENSOR VN: IO39/ADC3
- SENSOR VP: IO36/ADC0
- EN 按钮: 复位键

---

## 2. Arduino IDE 的下载、安装和使用方法

参考链接：[https://www.keyesrobot.cn/projects/Arduino/zh-cn/latest/](https://www.keyesrobot.cn/projects/Arduino/zh-cn/latest/)

<span style="color: rgb(255, 76, 65);">注意：</span><span style="background:#ff0;color:#000">Esp32主板_C_教程里所有课程使用的Arduino IDE版本：2.1.1 。</span>

---

## 3. 课程

---

### 项目01 Hello World

#### 1. 项目介绍：

对于ESP32的初学者，先从一些简单的开始学习吧！在这个项目中，你只需要一个ESP32主板，MicroUSB线和计算机就可以完成“Hello World!”项目。它不仅是ESP32主板和计算机的通信测试，也是ESP32的初级项目。这也是一个入门实验，让你进入计算机的编程世界。

#### 2. 项目元件：

| ![Img](./media/1.png)| ![Img](./media/2.png) |
| :--: | :--: |
|ESP32主板*1 | MicroUSB线*1 |

#### 3. 项目接线：

![Img](./media/3.png)

#### 4. 项目代码：

将使用一个简单的If()语句编程控制结构。Arduino IDE使用串行监视器来显示打印语句、传感器数据等信息。这是一个非常强大的工具，用于调试长代码。现在是你的第一个代码：

```C
//*************************************************************************************
/*
 * 名称   : Hello World
 * 功能   : 输入字母R，串口显示“Hello World”。
 * 作者   : http://www.keyes-robot.com/
*/
char val;//定义变量val.

void setup(){
Serial.begin(115200);// 设置波特率为115200. 
}

void loop(){
  if (Serial.available() > 0) {
    val=Serial.read();// 读取指令或字符从PC到Arduino，并赋值给val.
    if(val=='R') {  // 确定接收的指令或字符是否为“R”.    
     Serial.println("Hello World!");// 显示“Hello World !”字符串.
    }
  }
}
//*************************************************************************************
```

#### 5. 项目现象：

选择正确的主板类型ESP32 Dev Module和COM端口，点击Arduino IDE上的上传按钮![Img](./media/0.png)上传代码。上传成功后，利用MicroUSB线连接到计算机上电，单击![Img](./media/4.png)图标进入串行监视器，设置波特率为 **115200** ，在文本框输入字母“R”，按下回车键(Enter 键)，这样串口监视器打印“Hello World!”。

![Img](./media/5.png)

<span style="color: rgb(255, 76, 65);"><span style="font-size: 20px;">特别注意：</span></span> 如果上传代码不成功，可以再次点击![Img](./media/0.png)，当输出框中出现“**Connecting......**”时用手按住ESP32主板上的Boot键![Img](./media/WW1.png)，如果出现上传进度百分比数后则再松开Boot键，如下图所示：

![Img](./media/WW2.png)

![Img](./media/WW3.png)

#### 6. 代码说明

| 代码                | 说明                                                         |
| ------------------- | ------------------------------------------------------------ |
| char val            | 定义一个变量val                                              |
| Serial.begin(115200)  | 设置串口波特率为115200                                             |
| Serial.available( ) | 获取串口上可读取的数据的字节数，该数据已经到达并存储在接收缓存（共有64字节）中。Serial.available() > 0表示串口接收到了数据，可以读取。 |
| Serial.read( )      | 读取写入的串行数据。                                         |
| if( ){ }            | 如果“（ ）”里的条件满足，则执行“{ }”里的程序。               |
| Serial.println( )   | 换行输出数据。从串行端口输出数据，跟随一个回车和一个换行符。 |

---

### 项目02 点亮LED

#### 1. 项目介绍：

在这个项目中，我们将向你展示点亮LED。我们是使用ESP32主板的数字引脚来打开LED，使LED被点亮。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/7.png)|
| :--: | :--: | :--: |
|ESP32主板*1|面包板*1|红色LED*1|
|![Img](./media/8.png)| ![Img](./media/9.png)|![Img](./media/2.png)|
|220Ω电阻*1|面包板连接线*2|MicroUSB线*1|

#### 3. 元件知识：

**（1）LED**

![Img](./media/7.png)

LED是一种被称为“发光二极管”的半导体，是一种由半导体材料(硅、硒、锗等)制成的电子器件。它有正极和负极。短腿为负极，接GND，长腿为正极，接3.3V或5V。

![Img](./media/10.png)

**（2）五色环电阻**

电阻是电路中限制或调节电流流动的电子元件。左边是电阻器的外观，右边是电阻在电路中表示的符号。电阻(R)的单位为欧姆(Ω)，1 mΩ= 1000 kΩ，1kΩ= 1000Ω。

![Img](./media/abcdefg.png)

我们可以使用电阻来保护敏感组件，如LED。电阻的强度（以Ω为单位）用小色环标记在电阻器的主体上。每种颜色代表一个数字，你可以用电阻对照卡查找。

![Img](./media/11.png)

在这个套件中，我们提供了2个具有不同电阻值的五色环电阻。这里以2个五色环电阻为例：

220Ω电阻×10

![Img](./media/12.png)

1KΩ电阻×10

![Img](./media/13.png)

在相同的电压下，会有更小的电流和更大的电阻。电流、电压、电阻之间的联系可以用公式表示：I=U/R。在下图中，目前通过R1的电流: I = U / R = 3 V / 10 KΩ= 0.0003A= 0.3mA。

![Img](./media/14.png)

不要把电阻值很低的电阻直接连接在电源两极，这样会使电流过高而损坏电子元件。电阻是没有正负极之分。

**（3）面包板**

面包板是实验室中用于搭接电路的重要工具。面包板上有许多孔，可以插入集成电路和电阻等电路元件。熟练掌握面包板的使用方法是提高实验效率，减少实验故障出现几率的重要基础之一。下面就面包板的结构和使用方法做简单介绍。一个典型的面包板如下所示：

![Img](./media/15.png)

面包板的外观和内部结构如上图所示，常见的最小单元面包板分上、中、下三部分，上面和下面部分一般是由一行或两行的插孔构成的窄条，中间部分是由中间一条隔离凹槽和上下各5 行的插孔构成的条。

![Img](./media/15.png)

在面包板的两个窄条分别有两行插孔，两行之间是不连通的，一般是作为电源引入的通路。上方第一行标有“+”的一行有10组插孔（内部都是连通），均为正极；上方第二行标有“-”的一行有10组插孔，（内部都是连通），均为接地。面包板下方的第一行与第二行结构同上。如需用到整个面包板，通常将“+”与“+”用导线连接起来，“-”与“-”用导线连接起来。

中间部分宽条是由中间一条隔离凹槽和上下各5 行的插孔构成。在同一列中的5 个插孔是互相连通的，列和列之间以及凹槽上下部分则是不连通的。外观及结构如下图：

![Img](./media/17.png)

中间部分宽条的连接孔分为上下两部分，是面包板的主工作区，用来插接原件和面包板连接线。在同一列中的5个插孔（即a-b-c-d-e，f-g-h-i-j）是互相连通的；列和列之间以及凹槽上下部分是不连通的。在做实验的时候，通常是使用两窄一宽组成的小单元，在宽条部分搭接电路的主体部分，上面的窄条取一行做电源，下面的窄条取一行做接地。中间宽条用于连接电路，由于凹槽上下是不连通的，所以集成块一般跨插在凹槽上。

**(4)电源**

ESP32主板需要3.3V-5V电源，在本项目中，我们通过用MicroUSB线将ESP32主板和电脑连起来。

![Img](./media/3.png)

#### 4. 项目接线图：

![Img](./media/40.png)

#### 5. 项目代码：

```C
//*************************************************************************************
/*
 * 名称   : Turn_On_LED
 * 功能   : 点亮 LED
 * 作者   : http://www.keyes-robot.com/
*/
#define PIN_LED 15  // 定义LED的引脚为GPIO15.

void setup() {
  pinMode(PIN_LED, OUTPUT);  // 设置led引脚为输出模式.
}

void loop() {
  digitalWrite(PIN_LED, HIGH); //  点亮LED.
}
//*************************************************************************************
```

#### 6. 项目现象：

选择正确的主板类型ESP32 Dev Module和COM端口，点击Arduino IDE上的上传按钮![Img](./media/0.png)上传代码。项目代码上传成功后，利用MicroUSB线连接到计算机上电，可以看到的现象是：LED被点亮。

![Img](./media/19.png)

<span style="color: rgb(255, 76, 65);"><span style="font-size: 20px;">特别注意：</span></span> 如果上传代码不成功，可以再次点击![Img](./media/0.png)，当输出框中出现“**Connecting......**”时用手按住ESP32主板上的Boot键![Img](./media/WW1.png)，如果出现上传进度百分比数后则再松开Boot键，如下图所示：

![Img](./media/WW2.png)

![Img](./media/WW3.png)

#### 7. 代码说明:

| 代码                       | 说明                                                       |
| -------------------------- | ---------------------------------------------------------- |
| pinMode(PIN_LED, OUTPUT)    | 设置引脚的模式。OUTPUT为输出模式；INPUT为输入模式          |
| digitalWrite(PIN_LED, HIGH) | 设置引脚的输出电压为高\低电平。HIGH为高电平，LOW为低电平。 |

---

### 项目03 LED闪烁

#### 1. 项目介绍：

在这个项目中，我们将向你展示LED闪烁效果。我们是使用ESP32主板的数字引脚来打开LED，让它闪烁。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/7.png)|
| :--: | :--: | :--: |
|ESP32主板*1|面包板*1|红色LED*1|
|![Img](./media/8.png)| ![Img](./media/9.png)|![Img](./media/2.png)|
|220Ω电阻*1|面包板连接线*2|MicroUSB线*1|

#### 3. 项目接线图：

![Img](./media/40.png)

#### 4. 项目代码：

```C
//*************************************************************************************
/*
 * 名称   : LED_Blinking
 * 功能   : LED 闪烁1秒
 * 作者   : http://www.keyes-robot.com/
*/
#define PIN_LED 15  // 定义LED的引脚为GPIO15.

void setup(){
  pinMode(PIN_LED, OUTPUT);// 设置led引脚为输出模式.
}

void loop(){
  digitalWrite(PIN_LED, HIGH); // 点亮LED.
  delay(1000); // 等待1秒.
  digitalWrite(PIN_LED, LOW); // 熄灭LED.
  delay(1000); // 等待1秒
}
//*************************************************************************************
```

#### 5. 项目现象：

选择正确的主板类型ESP32 Dev Module和COM端口，点击Arduino IDE上的上传按钮![Img](./media/0.png)上传代码。项目代码上传成功后，利用MicroUSB线连接到计算机上电，可以看到的现象是：可以看到电路中的LED会反复闪烁。

![Img](./media/21.png)

<span style="color: rgb(255, 76, 65);"><span style="font-size: 20px;">特别注意：</span></span> 如果上传代码不成功，可以再次点击![Img](./media/0.png)，当输出框中出现“**Connecting......**”时用手按住ESP32主板上的Boot键![Img](./media/WW1.png)，如果出现上传进度百分比数后则再松开Boot键，如下图所示：

![Img](./media/WW2.png)

![Img](./media/WW3.png)

#### 6. 代码说明:

| 代码                       | 说明                                                       |
| -------------------------- | ---------------------------------------------------------- |
| pinMode(PIN_LED, OUTPUT)    | 设置引脚的模式。OUTPUT为输出模式；INPUT为输入模式          |
| digitalWrite(PIN_LED, HIGH) | 设置引脚的输出电压为高\低电平。HIGH为高电平，LOW为低电平。 |
| delay(1000)                | 将程序的执行暂停一段时间,也就是延时。单位是毫秒。          | 

---

### 项目04 交通灯

#### 1. 项目介绍：

交通灯在我们的日常生活中很普遍。根据一定的时间规律，交通灯是由红、黄、绿三种颜色组成的。每个人都应该遵守交通规则，这可以避免许多交通事故。在这个项目中，我们将使用ESP32主板和一些led(红，黄，绿)来模拟交通灯。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/7.png)|![Img](./media/22.png)|
| :--: | :--: | :--: |:--: |
|ESP32主板*1|面包板*1|红色LED*1|黄色LED*1|
|![Img](./media/23.png)|![Img](./media/8.png)| ![Img](./media/9.png)|![Img](./media/2.png)|
|绿色LED*1|220Ω电阻*3|面包板连接线若干|MicroUSB线*1|

#### 3. 项目接线图： 

![Img](./media/41.png)

#### 4. 项目代码：

```C
//*********************************************************************************
/*
 * 名称   : Traffic_Lights
 * 功能   : 模拟交通灯
 * 作者   : http://www.keyes-robot.com/ 
*/
#define PIN_LED_RED   0   //定义红色LED的引脚为GPIO0
#define PIN_LED_YELLOW   2   //定义黄色LED的引脚为GPIO2
#define PIN_LED_GREEN  15   //定义绿色LED的引脚为GPIO15

void setup() {
  pinMode(PIN_LED_RED, OUTPUT);  // 将红色LED引脚设置为输出模式
  pinMode(PIN_LED_YELLOW, OUTPUT);  // 将黄色LED引脚设置为输出模式
  pinMode(PIN_LED_GREEN, OUTPUT);  // 将绿色LED的引脚设置为输出模式
}

void loop(){
  digitalWrite(PIN_LED_GREEN, HIGH); // 点亮绿色LED
  delay(5000); // 延时5秒
  digitalWrite(PIN_LED_GREEN, LOW); // 熄灭绿色LED
  for(int i=0;i<3;i++){// 闪烁3次
    digitalWrite(PIN_LED_YELLOW, HIGH); //点亮黄色LED
    delay(500); // 延时0.5秒
    digitalWrite(PIN_LED_YELLOW, LOW); // 熄灭黄色LED
    delay(500); // 延时0.5秒
  } 
  digitalWrite(PIN_LED_RED, HIGH); // 点亮红色LED
  delay(5000); // 延时5秒
  digitalWrite(PIN_LED_RED, LOW); // 熄灭红色LED
}
//*********************************************************************************
```

#### 5. 项目现象：

选择正确的主板类型ESP32 Dev Module和COM端口，点击Arduino IDE上的上传按钮![Img](./media/0.png)上传代码。项目代码上传成功后，利用MicroUSB线连接到计算机上电，可以看到的现象是：1.首先，绿灯会亮5秒，然后熄灭；2.其次，黄灯会闪烁3次，然后熄灭；3.然后，红灯会亮5秒，然后熄灭；4.继续运行上述1-3个步骤。

![Img](./media/AB7.jpg)

<span style="color: rgb(255, 76, 65);"><span style="font-size: 20px;">特别注意：</span></span> 如果上传代码不成功，可以再次点击![Img](./media/0.png)，当输出框中出现“**Connecting......**”时用手按住ESP32主板上的Boot键![Img](./media/WW1.png)，如果出现上传进度百分比数后则再松开Boot键，如下图所示：

![Img](./media/WW2.png)

![Img](./media/WW3.png)

#### 6. 代码说明:

可以参照项目03和项目05的代码说明，这里就不多做介绍了。

---

### 项目05 呼吸灯

#### 1. 项目介绍：

在之前的研究中，我们知道LED有亮/灭状态，那么如何进入中间状态呢?如何输出一个中间状态让LED“半亮”?这就是我们将要学习的。呼吸灯，即LED由灭到亮，再由亮到灭，就像“呼吸”一样。那么，如何控制LED的亮度呢? 我们将使用ESP32主板的PWM来实现这个目标。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/7.png)|
| :--: | :--: | :--: |
|ESP32主板*1|面包板*1|红色LED*1|
|![Img](./media/8.png)| ![Img](./media/9.png)|![Img](./media/2.png)|
|220Ω电阻*1|面包板连接线*2|MicroUSB线*1|

#### 3. 元件知识：

![Img](./media/24.png)

**模拟信号 & 数字信号** 

模拟信号在时间和数值上都是连续的信号。相反，数字信号或离散时间信号是由一系列数字组成的时间序列。生活中的大多数信号都是模拟信号，一个熟悉的模拟信号的例子是：全天的温度是连续不断变化的，而不是突然从0到10的瞬间变化。然而，数字信号的值可以瞬间改变。这个变化用数字表示为1和0(二进制代码的基础)。如下图所示，我们可以更容易地看出它们的差异。

![Img](./media/25.png)

在实际应用中，我们经常使用二进制作为数字信号，即一系列的0和1。由于二进制信号只有两个值(0或1)，因此具有很大的稳定性和可靠性。最后，可以将模拟信号和数字信号相互转换。

**PWM：**

脉宽调制(PWM)是一种利用数字信号控制模拟电路的有效方法。普通处理器不能直接输出模拟信号。PWM技术使这种转换(将数字信号转换为模拟信号)非常方便。PWM技术利用数字引脚发送一定频率的方波，即高电平和低电平的输出，交替持续一段时间。每一组高电平和低电平的总时间一般是固定的，称为周期(注:周期的倒数是频率)。高电平输出的时间通常称为脉宽，占空比是脉宽(PW)与波形总周期(T)之比的百分比。高电平输出持续时间越长，占空比越长，模拟信号中相应的电压也就越高。下图显示了对应于脉冲宽度0%-100%的模拟信号电压在0V-3.3V(高电平为3.3V)之间的变化情况.

![Img](./media/26.png)

PWM占空比越长，输出功率越高。既然我们了解了这种关系，我们就可以用PWM来控制LED的亮度或直流电机的速度等等。从上面可以看出，PWM并不是真实的模拟信号，电压的有效值等于相应的模拟信号。因此，我们可以控制LED和其他输出模块的输出功率，以达到不同的效果。

#### 4. 项目接线图： 

![Img](./media/40.png)

#### 5. 项目代码：

```C
//**********************************************************************************
/*
 * 名称   : Breathing_LED
 * 功能   : 使用PWM让led灯像呼吸一样忽明忽暗。
 * 作者   : http://www.keyes-robot.com/
*/
#define PIN_LED   15   //定义LED的引脚为GPIO15
#define CHN       0   //定义PWM通道
#define FRQ       1000  //定义PWM频率
#define PWM_BIT   8     //定义PWM精确度
void setup() {
  ledcSetup(CHN, FRQ, PWM_BIT); //初始化PWM通道
  ledcAttachPin(PIN_LED, CHN);  //将led引脚连接到pwm通道
}

void loop() {
  for (int i = 0; i < 255; i++) { //使光线逐渐变亮
    ledcWrite(CHN, i);
    delay(10);
  }
  for (int i = 255; i > -1; i--) {  //使光线逐渐变暗
    ledcWrite(CHN, i);
    delay(10);
  }
}      
//**********************************************************************************
```

#### 6. 项目现象：

选择正确的主板类型ESP32 Dev Module和COM端口，点击Arduino IDE上的上传按钮![Img](./media/0.png)上传代码。项目代码上传成功后，利用MicroUSB线连接到计算机上电，可以看到的现象是：电路中的LED从暗逐渐变亮，再从亮逐渐变暗，就像呼吸一样。

![Img](./media/28.png)

<span style="color: rgb(255, 76, 65);"><span style="font-size: 20px;">特别注意：</span></span> 如果上传代码不成功，可以再次点击![Img](./media/0.png)，当输出框中出现“**Connecting......**”时用手按住ESP32主板上的Boot键![Img](./media/WW1.png)，如果出现上传进度百分比数后则再松开Boot键，如下图所示：

![Img](./media/WW2.png)

![Img](./media/WW3.png)

#### 7. 代码说明:

| 代码                       | 说明                    |
| -------------------------- | ------------------------------------------------------------ |
|for (int i = 0; i < 255; i++)|i的取值范围就是0～255， 超过255后又会回到0。所以当你的i从0逐渐增加到255后，再执行i++，i的值不是256，而是回到了0，这仍然符合i<=255的要求，所以循环继续。当你改成i<=254时，i循环到254后，再执行i++是255，让i<=254的条件为假，从而结束循环。|
| ledcSetup(CHN,FRQ, WM_BIT) | ledcSetup这个函数是用来设置pwm通道的。用法是ledcSetup（通道号，频率，计数位数）。通道号，取值0 ~ 15。计数位数，取值0 ~ 20（该值决定ledcWrite函数中占空比的最大值，如该值写10，则占空比最大可写2^10-1=1023。 |
| ledcWrite(CHN, i)          | ledcWrite这个函数用来指定通道输出一定占空比的波形。用法是：ledcWrite(通道, 占空比)。 |

---

### 项目06 流水灯

#### 1. 项目介绍：

在日常生活中，我们可以看到许多由不同颜色的led组成的广告牌。他们不断地改变灯光(像流水一样)来吸引顾客的注意。在这个项目中，我们将使用ESP32主板控制3个LED灯实现流水的效果。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/7.png)|
| :--: | :--: | :--: |
|ESP32主板*1|面包板*1|红色LED*3|
|![Img](./media/8.png)| ![Img](./media/9.png)|![Img](./media/2.png)|
|220Ω电阻*3|面包板连接线若干|MicroUSB线*1|

#### 3. 项目接线图:

![Img](./media/42.png)

#### 4. 项目代码：

```C
//**********************************************************************************
/*
 * 名称   : Flowing_Water_Light
 * 功能   : 流水灯
 * 作者   : http://www.keyes-robot.com/ 
*/
byte ledPins[] = {0, 2, 15}; // LED的I/O引脚
int ledCounts; // LED 数量

void setup(){
   ledCounts = sizeof(ledPins);
   for (int i = 0; i < ledCounts; i++) {
     pinMode(ledPins[i], OUTPUT);   // 设置I/O引脚为输出模式
   }
}
void loop(){
   for (int i = 0; i < ledCounts; i++) {
     digitalWrite(ledPins[i], HIGH); // 设置I/O引脚为高，依次点亮led灯
     delay(100); // 延时0.1秒
     digitalWrite(ledPins[i], LOW);  // 设置I/O引脚为低，依次熄灭led灯
   }
   for (int i = ledCounts - 1; i > -1; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
   }  
}
//**********************************************************************************
```

#### 5. 项目现象：

选择正确的主板类型ESP32 Dev Module和COM端口，点击Arduino IDE上的上传按钮![Img](./media/0.png)上传代码。项目代码上传成功后，利用MicroUSB线连接到计算机上电，可以看到的现象是：电路中的3个LED会逐渐亮起来，然后逐渐熄灭，就像电池充电一样。

![Img](./media/AB6.jpg)

<span style="color: rgb(255, 76, 65);"><span style="font-size: 20px;">特别注意：</span></span> 如果上传代码不成功，可以再次点击![Img](./media/0.png)，当输出框中出现“**Connecting......**”时用手按住ESP32主板上的Boot键![Img](./media/WW1.png)，如果出现上传进度百分比数后则再松开Boot键，如下图所示：

![Img](./media/WW2.png)

![Img](./media/WW3.png)

#### 6. 代码说明:

可以参照项目03和项目05的代码说明，这里就不多做介绍了。

---

### 项目07 有源蜂鸣器

#### 1. 项目介绍：

有源蜂鸣器模块上有一个发声元件----有源蜂鸣器。它被广泛用作电脑、打印机、报警器、电子玩具、电话、计时器等的发声元件。它有一个内在的振动源，需连接3.3V~5V电源，即可持续发出嗡嗡声。在这个项目中，我们将使用ESP32主板控制有源蜂鸣器发出“滴滴”声。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/29.png)|![Img](./media/30.jpg)|![Img](./media/2.png)|
| :--: | :--: | :--: | :--: |:--: |
|ESP32主板*1|面包板*1|有源蜂鸣器模块*1|公对母杜邦线若干|MicroUSB线*1|

#### 3. 元件知识：

<span style="color: rgb(255, 76, 65);">注意：本教程使用的是有源蜂鸣器。</span>

![Img](./media/29.png)

有源蜂鸣器和无源蜂鸣器的“源”不是指电源，而是指震荡源。

**有源蜂鸣器**：内部自带震荡源，所以一触发就能发声，发声频率固定。有源蜂鸣器的优点是程序控制方便，声压高。有源自激型蜂鸣器工作发声原理如下：直流电源输入经过振荡系统的放大和取样电路在谐振装置作用下产生声音信号。

**模块参数：**

工作电压: DC 3.3 ~ 5V 

工作温度：-10°C ~ +50°C

控制信号：数字信号

尺寸：32 mm x 23.8 mm x 12.3 mm

定位孔大小：直径为 4.8 mm

**无源蜂鸣器**: 内部不带震荡源，如果直接通直流电信号无源蜂鸣器是没有声音的，因为磁路恒定，振动膜片一直处在吸附状态，不能振动发音。根据不同需求，一般我们通过方波去驱动，然后通过更换方波的频率来实现不同音效。

**总结：有源蜂鸣器内部带震荡源，发声频率固定。无源内部不带震荡源，通过方波去驱动，发音频率可改变。**


#### 4. 项目接线图：

![Img](./media/43.png)

#### 5. 项目代码：

```C
//**********************************************************************************
/*
 * 名称   : Active buzzer
 * 功能   : 有源蜂鸣器产生声音
 * 作者   : http://www.keyes-robot.com/
*/
#define buzzerPin  15   //定义蜂鸣器的引脚为GPIO15

void setup () {
  pinMode (buzzerPin, OUTPUT);  //设置蜂鸣器引脚为输出模式
}

void loop () {
  digitalWrite (buzzerPin, HIGH); //发声
  delay (500); //延时0.5秒
  digitalWrite (buzzerPin, LOW);  //停止发声
  delay (500); //延时0.5秒
}
//**********************************************************************************
```

#### 6. 项目现象：

选择正确的主板类型ESP32 Dev Module和COM端口，点击Arduino IDE上的上传按钮![Img](./media/0.png)上传代码。项目代码上传成功后，利用MicroUSB线连接到计算机上电，可以看到的现象是：有源蜂鸣器发出“滴滴”声。

![Img](./media/AB5.jpg)

<span style="color: rgb(255, 76, 65);"><span style="font-size: 20px;">特别注意：</span></span> 如果上传代码不成功，可以再次点击![Img](./media/0.png)，当输出框中出现“**Connecting......**”时用手按住ESP32主板上的Boot键![Img](./media/WW1.png)，如果出现上传进度百分比数后则再松开Boot键，如下图所示：

![Img](./media/WW2.png)

![Img](./media/WW3.png)

#### 7. 代码说明:

可以参照项目03的代码说明，这里就不多做介绍了。

---

### 项目08 继电器控制LED

#### 1. 项目介绍：

在日常生活中，我们一般使用交流来驱动电气设备，有时我们会用开关来控制电器。如果将开关直接连接到交流电路上，一旦发生漏电，人就有危险。从安全的角度考虑，我们特别设计了这款具有NO(常开)端和NC(常闭)端的继电器模块。在这节课我们将学习一个比较特殊、好用的开关，就是继电器模块，使用继电器模块控制LED灯亮灭。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/32.png)|![Img](./media/7.png)|![Img](./media/A25.png)|
| :--: | :--: | :--: |:--: |:--: |
|ESP32主板*1|面包板*1|继电器模块*1|红色LED*1|一字螺丝刀*1|
|![Img](./media/30.jpg)|![Img](./media/2.png)|![Img](./media/8.png)| ![Img](./media/9.png)| |
|公对母杜邦线若干|MicroUSB线*1|220Ω电阻*1|面包板连接线若干| |

#### 3. 元件知识：

![Img](./media/32.png)

**继电器：** 继电器能兼容多种单片机控制板，是用小电流去控制大电流运作的一种“自动开关”。它可以让单片机控制板驱动3A以下负载，如LED灯带、直流马达、微型水泵、电磁阀可插拔式接口设计，方便使用。继电器有3个接线柱用于外接电路，分别为NO、COM和NC端（背后丝印）。

![Img](./media/33.png)

**模块参数:**

工作电压: DC 5V 

工作电流: 50 mA

最大功率: 0.25 W

控制信号: 数字信号

触电电流: 小于 3 A

工作温度：-10°C ~ +50°C

尺寸：47.6mm x 23.8mm x 19mm

定位孔大小：直径为4.8mm

**模块原理图:**

![Img](./media/34.png)

一个继电器拥有一个动触点以及两个静触点A和B。

当开关K断开时，继电器线路无电流通过，此时动触点与静触点B相接触，上半部分的电路导通。静触点B被称为常闭触点（NC）。常闭——NC（normal close）通常情况下是关合状态，即线圈未得电的情况下闭合的。

当开关K闭合时，继电器电路通过电流产生磁力，此时动触点与静触点A相接触，下半部分电路导通。静触点A被称为常开触点（NO）。常开——NO（normal open）通常情况下是断开状态，即线圈未得电的情况下断开的。

而动触点也被称为公共触点（COM）。

继电器简单来说就是一个开关，VCC表示电源正极、GND表示电源负极、IN表示信号输入脚，COM表示公共端，NC（normal close）表示常闭端，NO(normal open)表示常开端。

![Img](./media/35.png)

#### 4. 项目接线图：

<br>
<span style="color: rgb(61, 167, 66);"> **特别注意：** 接线前，需要用一字螺丝刀将继电器模块的NO端口和COM端口处的螺丝扭松，将面包板连接线的一端插入NO端口和COM端口处；接好线后，再用一字螺丝刀将NO端口和COM端口处的螺丝扭紧。</span>
<br>

![Img](./media/44.png)

#### 5. 项目代码：

```C
//**********************************************************************************
/*
 * 名称   : Relay_Control_LED
 * 功能   : 继电器控制LED亮与灭
 * 作者   : http://www.keyes-robot.com/ 
*/
#define  Relay 15  //定义继电器的引脚为GPIO15

void setup() {
  pinMode(Relay, OUTPUT); //设置继电器的引脚为输出模式
}

void loop() {
  digitalWrite(Relay, HIGH); //打开继电器
  delay(1000); //延时1秒
  digitalWrite(Relay, LOW); //关闭继电器
  delay(1000); //延时1秒
}
//**********************************************************************************
```
#### 6. 项目现象：

选择正确的主板类型ESP32 Dev Module和COM端口，点击Arduino IDE上的上传按钮![Img](./media/0.png)上传代码。项目代码上传成功后，利用MicroUSB线连接到计算机上电，可以看到的现象是：继电器将循环开与关，开启1秒LED点亮1秒，关闭1秒LED熄灭1秒。同时可以听到继电器开与关的声音，还可以看到继电器上的指示灯指示状态的变化。

![Img](./media/AB4.jpg)

<span style="color: rgb(255, 76, 65);"><span style="font-size: 20px;">特别注意：</span></span> 如果上传代码不成功，可以再次点击![Img](./media/0.png)，当输出框中出现“**Connecting......**”时用手按住ESP32主板上的Boot键![Img](./media/WW1.png)，如果出现上传进度百分比数后则再松开Boot键，如下图所示：

![Img](./media/WW2.png)

![Img](./media/WW3.png)

#### 7. 代码说明:

可以参照项目03的代码说明，这里就不多做介绍了。

---

### 项目09 声音传感器

#### 1. 项目介绍：

声音传感器将外界声音的大小转换成对应的模拟信号，然后通过模块上的信号输出端输出。在本项目中，我们将测试当前环境中的声音对应的ADC值、DAC值和输出的电压值。声音越大，ADC值、DAC值和电压值越大；并在串口监视器上显示测试结果。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/37.png)|
| :--: | :--: | :--: |
|ESP32主板*1|面包板*1|声音传感器模块*1|
|![Img](./media/30.jpg)|![Img](./media/2.png)|![Img](./media/A25.png)|
|公对母杜邦线若干|MicroUSB线*1|一字螺丝刀*1|

#### 3. 元件知识：

![Img](./media/37.png)

**声音传感器:** 声音传感器通常用于检测周围环境中的声音响度。微型控制板可以通过模拟输入接口采集其输出信号。S引脚是模拟输出，是麦克风电压信号的实时输出。传感器附带一个电位器，这样你就可以调整信号强度。你可以使用它来制作一些交互式作品，如语音操作的开关等。

**模块参数:**

工作电压: DC 3.3 ~ 5V 

工作电流: 1.5MA

最大功率: 0.075W

工作温度：-10°C ~ +50°C

输出信号: 模拟信号

尺寸：32 mm x 23.8 mm x 10.3 mm

定位孔大小：直径为 4.8 mm

**模块原理图:**

![](media/38.png)

声音传感器主要由一个高感度麦克风元件和LM386音频功率放大器芯片组成。高感度麦克风元件用于检测外界的声音。利用LM386音频功率放大器芯片设计对高感度麦克风检测到的声音进行放大的电路，最大倍数为200倍。使用时我们可以通过旋转传感器上电位器，调节声音的放大倍数。顺时针调节电位器到尽头，放大倍数最大。

#### 4. 项目接线图：

![Img](./media/45.png)

#### 5. 项目代码：

```C
//**********************************************************************************
/*
 * 名称   : Sound_Sensor
 * 功能   : 读取声音传感器的值，将其转化为ADC、DAC和电压值
 * 作者   : http://www.keyes-robot.com/  
*/
#define PIN_ANALOG_IN 36   //声音传感器的模拟引脚定义为GPIO36

void setup() {
  Serial.begin(115200);   //波特率设置为115200
  pinMode(PIN_ANALOG_IN, INPUT);    //将传感器的引脚设置为输入模式
}

void loop() {
  int adcVal = analogRead(PIN_ANALOG_IN);    //使用analogRead()函数获取ADC值
  int dacVal = map(adcVal, 0, 4095, 0, 255);   //使用map()函数将ADC值转换为DAC值
  double voltage = adcVal / 4095.0 * 3.3;  //输出电压
  Serial.print("ADC Val: "); //打印字符串ADC Val:
  Serial.print(adcVal); //打印ADC值, DAC值和电压值
  Serial.print("  DAC Val: ");  //打印字符串DAC Val:
  Serial.print(dacVal);  //打印DAC值
  Serial.print("  Voltage: ");  //打印字符串Voltage:
  Serial.print(voltage);  //打印电压值
  Serial.println(" V");  //打印字符串V
  delay(200); 
}
//**********************************************************************************
```

#### 6. 项目现象：

选择正确的主板类型ESP32 Dev Module和COM端口，点击Arduino IDE上的上传按钮![Img](./media/0.png)上传代码。项目代码上传成功后，利用MicroUSB线连接到计算机上电，此时声音传感器上的电源指示灯点亮。

![Img](media/48.png)

点击![Img](./media/4.png)打开串口监视器，设置波特率为**115200**，串口监视器打印出声音传感器接收到的声音对应的ADC值、DAC值和电压值。对准模块上的MIC头大声说话（或大呼气）时，可以看到接收到的声音对应的ADC值、DAC值和电压值变大。（**注意：如果声音变化对应的模拟值没有变化并且一直都是数字0，需要用一字螺丝刀顺时针旋转电位器来调节。**）

![Img](./media/AB3.jpg)

![Img](./media/39.png)

<span style="color: rgb(255, 76, 65);"><span style="font-size: 20px;">特别注意：</span></span> 如果上传代码不成功，可以再次点击![Img](./media/0.png)，当输出框中出现“**Connecting......**”时用手按住ESP32主板上的Boot键![Img](./media/WW1.png)，如果出现上传进度百分比数后则再松开Boot键，如下图所示：

![Img](./media/WW2.png)

![Img](./media/WW3.png)

#### 7. 代码说明:

| 代码                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| pinMode(PIN_ANALOG_IN, INPUT); | 由“ int PIN_ANALOG_IN = 36; ”知道，定义声音传感器模块的模拟管脚为GPIO36。“INPUT”设置为输入模式。通过pinMode()配置为INPUT必须使用上拉或下拉电阻。但是，我们的模块已经使用上拉电阻R1，该电阻的目的是在开关断开时将引脚拉至已知状态。通常选择一个4.7KΩ/10KΩ的电阻，因为它的阻值足够低，可以可靠地防止输入悬空。同时，该阻值也要足够高，以使开关闭合时不会消耗太多电流。如果使用下拉电阻，则当开关断开时，输入引脚将为低电平；当开关闭合时，输入引脚将为高电平。如果使用上拉电阻，则当开关断开时，输入引脚将为高电平；当开关闭合时，输入引脚将为低电平。 |
| analogRead(PIN_ANALOG_IN)                 | 为了兼容性，默认analogRead()分辨率为 10 位。详细了解请参考链接：https://vimsky.com/examples/usage/arduino-language-functions-analog-io-analogread-ar.html 。这个函数是从指定的模拟引脚PIN_ANALOG_IN读取声音传感器的模拟信号。ESP32板包含一个多通道、12位模数转换器。 这意味着它会将 0 和工作电压（5V 或 3.3V，我们这里是3.3V）之间的输入电压映射为0和4095之间的整数值。这会产生以下分辨率：3.3V/4096单位即每单位 0.0008V。 |
| int dacVal = map(adcVal, 0, 4095, 0, 255) | 将adcVal读到的值从 0 ~ 4095 映射到 0 ~ 255，也就是转换为占空比对应的值。 |
| double voltage = adcVal / 4095.0 * 3.3    | 以double（双精度）浮点型输出电压值。                         |
| Serial.begin(115200)     | 初始化串口通信，并设置波特率为115200。                         |
| Serial.print( )   | 未换行输出数据。从串行端口输出数据，跟随一个回车和一个未换行符。 |
| Serial.println( )   | 换行输出数据。从串行端口输出数据，跟随一个回车和一个换行符。 |

---

### 项目10 声音传感器控制LED

#### 1. 项目介绍：

上一项目中我们已经学习了声音传感器的工作原理，这一项目中我们将声音传感器和LED灯组合实验，实现声音传感器检测外界声音大小输出的模拟值大于一定值时LED快速闪烁的效果。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/37.png)|![Img](./media/7.png)|
| :--: | :--: | :--: |:--: |
|ESP32主板*1|面包板*1|声音传感器模块*1|红色LED*1|
|![Img](./media/30.jpg)|![Img](./media/2.png)|![Img](./media/8.png)| ![Img](./media/9.png)|
|公对母杜邦线若干|MicroUSB线*1|220Ω电阻*1|面包板连接线若干|

#### 3. 项目接线图：

![Img](./media/46.png)

#### 4. 项目代码：

<span style="color: rgb(255, 76, 65);">注意：</span>代码中的阈值500可以根据实际情况更改的。

```C
//**********************************************************************************
/*  
 * 名称   : Sound_Sensor_Control_LED
 * 功能   : 声音传感器控制LED
 * 作者   : http://www.keyes-robot.com/ 
*/
int item = 0;
void setup() {
  Serial.begin(115200); //设置串口波特率为115200
  pinMode(36, INPUT);    //将声音传感器连接到GPIO36上，并设置为输入模式
  pinMode(2, OUTPUT);  //将LED连接到GPIO2上，并设置为输出模式
}

void loop() {
  item = analogRead(36);   //声音传感器读取声音大小，将读取到的模拟值赋予变量Item
  Serial.println(item);  //串口打印声音传感器的模拟信号
  if (item > 500) {  //模拟值大于500
    digitalWrite(2, HIGH);  //打开LED
    delay(500);  //延迟 500ms
    digitalWrite(2, LOW);  //关闭LED
    delay(500);  //延迟 500ms
  } else {  //否则，模拟值不大于500
    digitalWrite(2, LOW);  //关闭LED
  }
}
//**********************************************************************************
```

#### 5. 项目现象：

选择正确的主板类型ESP32 Dev Module和COM端口，点击Arduino IDE上的上传按钮![Img](./media/0.png)上传代码。项目代码上传成功后，利用MicroUSB线连接到计算机上电，可以看到的现象是：你会看到的现象是：对准模块上的MIC头大声说话（或大呼气），当声音传感器接收到的声音对应的模拟值大于500时，外接LED灯快速闪烁。

![Img](./media/AB2.jpg)

<span style="color: rgb(255, 76, 65);"><span style="font-size: 20px;">特别注意：</span></span> 如果上传代码不成功，可以再次点击![Img](./media/0.png)，当输出框中出现“**Connecting......**”时用手按住ESP32主板上的Boot键![Img](./media/WW1.png)，如果出现上传进度百分比数后则再松开Boot键，如下图所示：

![Img](./media/WW2.png)

![Img](./media/WW3.png)

#### 6. 代码说明:

| 代码                   | 说明                                     |
| ---------------------- | ---------------------------------------- |
| item = analogRead(36); | 将声音传感器连接到GPIO36上，读取声音传感器检测到声音大小转化成对应的模拟值。 |
| item > 500              | 声音大小检测，检测到声音大小的模拟值大于500。|
| if( ){ } else{ }       | 如果（ ）里的表达式为真，则执行 if { }块内的代码。如果（ ）里表达式为假 ，则执行 else { }块内的代码。 |
| digitalWrite(2, HIGH)  | LED灯点亮。                      |
| digitalWrite(2, LOW)  | LED灯熄灭。                      |

---

### 项目11 声音检测报警系统

#### 1. 项目介绍：

前面的项目中我们已经学习了声音传感器的工作原理和声音传感器控制LED灯快速闪烁的效果。那么，在本项目中，我们将结合声音传感器、有源蜂鸣器和LED灯来模拟声音检测报警系统。

#### 2. 项目元件：

|![Img](./media/1.png)|![Img](./media/6.png)|![Img](./media/37.png)|![Img](./media/29.png)|![Img](./media/7.png)|
| :--: | :--: | :--: |:--: |:--: |
|ESP32*1|面包板*1|声音传感器模块*1|有源蜂鸣器*1|红色LED*1|
|![Img](./media/30.jpg)|![Img](./media/2.png)|![Img](./media/8.png)| ![Img](./media/9.png)| |
|公对母杜邦线若干|MicroUSB线*1|220Ω电阻*1|面包板连接线若干| |

#### 3. 项目接线图：

![Img](./media/47.png)

#### 4. 项目代码：

<span style="color: rgb(255, 76, 65);">注意：</span>代码中的阈值500可以根据实际情况更改的。

```C
//**********************************************************************************
/*  
 * 名称   : Sound_Detection_Alarm_System
 * 功能   : 声音传感器控制LED和蜂鸣器
 * 作者   : http://www.keyes-robot.com/ 
*/
int item = 0;
void setup() {
  Serial.begin(115200); //设置串口波特率为115200
  pinMode(36, INPUT);    //将声音传感器连接到GPIO36上，并设置为输入模式
  pinMode(2, OUTPUT);  //将LED连接到GPIO2上，并设置为输出模式
  pinMode(0, OUTPUT); //将有源蜂鸣器连接到GPIO0上，并设置为输出模式
}

void loop() {
  item = analogRead(36);   //读取声音传感器的模拟值，将读取到模拟值赋予变量Item
  Serial.println(item);  //串口打印声音传感器输出的模拟信号
  if (item > 500) {  //模拟值大于500
    digitalWrite(0, HIGH); //打开蜂鸣器
    digitalWrite(2, HIGH);  //打开LED
    delay(500);  //延迟 500ms
    digitalWrite(0, LOW);  //关闭蜂鸣器
    digitalWrite(2, LOW);  //关闭LED
    delay(500);  //延迟 500ms
  } else {  //否则，模拟值不大于500
    digitalWrite(0, LOW); //关闭蜂鸣器
    digitalWrite(2, LOW);  //关闭LED
  }
}
//**********************************************************************************
```

#### 5. 项目现象：

选择正确的主板类型ESP32 Dev Module和COM端口，点击Arduino IDE上的上传按钮![Img](./media/0.png)上传代码。项目代码上传成功后，利用MicroUSB线连接到计算机上电，可以看到的现象是：对准模块上的MIC头大声说话（或大呼气），当声音传感器接收到的声音对应的模拟值大于500时，有源蜂鸣器发出警报，外接LED灯快速闪烁。

![Img](./media/AB1.jpg)

<span style="color: rgb(255, 76, 65);"><span style="font-size: 20px;">特别注意：</span></span> 如果上传代码不成功，可以再次点击![Img](./media/0.png)，当输出框中出现“**Connecting......**”时用手按住ESP32主板上的Boot键![Img](./media/WW1.png)，如果出现上传进度百分比数后则再松开Boot键，如下图所示：

![Img](./media/WW2.png)

![Img](./media/WW3.png)

#### 6. 代码说明:

可以参照项目10的代码说明，这里就不多做介绍了。

---







