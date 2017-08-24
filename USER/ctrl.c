#include "ctrl.h"

/*
PD3 ----->  SIG         输入中断、输出
PD2 ----->  CHECK       
PC6 ----->  T1          输出
PC5 ----->  T2          输出
PA3 ----->  REV         输入中断
PD4 ----->  T_PWR       输出
*/
//--------------------功能对应IO口------------------------------------
void GPIOInit()
{
  
  GPIO_Init(GPIOC, GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_FAST);
  GPIO_Init(GPIOC, GPIO_PIN_6, GPIO_MODE_OUT_PP_LOW_FAST);
  
  GPIO_Init(GPIOD, GPIO_PIN_4, GPIO_MODE_OUT_PP_LOW_FAST);
  
  GPIO_Init(GPIOA, GPIO_PIN_3, GPIO_MODE_IN_FL_IT);
  
  GPIO_Init(GPIOD, GPIO_PIN_3, GPIO_MODE_IN_FL_IT);
  
  EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOC, EXTI_SENSITIVITY_FALL_ONLY);//超声波接收信号   下降沿中断
  
  EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOD, EXTI_SENSITIVITY_RISE_ONLY);//触发信号   上升沿中断
}

void Delay_125us()
{
  asm("nop"); asm("nop"); asm("nop"); asm("nop");
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  
  asm("nop"); asm("nop"); asm("nop"); asm("nop");
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  
  asm("nop"); asm("nop"); asm("nop"); asm("nop");
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop");
  
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop");
  
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop");
  
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 

}//176  个机器周期 ？

//一次 for 循环8个周期 
//16*12.5 = 200 ??


//mode 0,1:互补翻转   2：两端口置低
void Port(uint8_t mode)
{
  if (mode == 2)
  {
    T1_OFF;
    T2_OFF;
  }
  else if (mode)
  {
    T1_ON;
    T2_OFF;
  }
  else
  {
    T1_OFF;
    T2_ON;
  }  
}