# 导入 Pin，ADC 和 time 库.
from machine import ADC, Pin
import time 

# 定义声音传感器，led和有源蜂鸣器的引脚. 
sensor_sound = ADC(Pin(36))
sensor_sound.atten(ADC.ATTN_11DB)
sensor_sound.width(ADC.WIDTH_12BIT)
led = Pin(2, Pin.OUT)
buzzer = Pin(0, Pin.OUT)   
 
while True: 
      adcvalue = sensor_sound.read()
      if adcvalue > 500:
          print(adcvalue, "Buzzer sounds and led blinking!")
          buzzer.value(1)
          led.value(1) 
          time.sleep(0.5)
          buzzer.value(0) 
          led.value(0)
          time.sleep(0.5)         
      else:
          print(adcvalue, "Buzzer won't sound and led off!")
          buzzer.value(0)
          led.value(0)
          time.sleep(0.5)