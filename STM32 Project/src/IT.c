#include "IT.h"
#include "delay.h"
 
uint8_t CLK=0;
extern uint16_t count;
void SysTick_Handler()
{
	TimingDelay_Decrement();
}
void TIM6_DAC_IRQHandler()
{

	CLK=~CLK;
if ( CLK==255)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_6);

	count++;	
}
	else
	{
		GPIO_ResetBits(GPIOB,GPIO_Pin_6);

	}
	/////////


	TIM_ClearITPendingBit(TIM6, TIM_IT_Update);
	
}
