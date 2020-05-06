#include "IO_init.h"
	
GPIO_InitTypeDef GPIO_InitStructure;
NVIC_InitTypeDef   NVIC_InitStructure;
EXTI_InitTypeDef   EXTI_InitStructure;
USART_InitTypeDef USART_InitStructure;
TIM_ICInitTypeDef  TIM_ICInitStructure;
TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
TIM_OCInitTypeDef  TIM_OCInitStructure;
uint16_t PrescalerValue = 0;
	
SPI_InitTypeDef SPI_InitTypeDefStruct;
GPIO_InitTypeDef GPIO_InitStructure;

void Temp_SPI_init()
{
RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB , ENABLE);
		
	
GPIO_InitStructure.GPIO_Pin =GPIO_Pin_6 | GPIO_Pin_13 ;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
GPIO_Init(GPIOB, &GPIO_InitStructure);
	
GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_14;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
GPIO_Init(GPIOB, &GPIO_InitStructure);

}
//===========================++===============================//


void Sample_Timer_init()
{
	PrescalerValue = (uint16_t) ((SystemCoreClock / 2) / 4000000) - 1;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);
	NVIC_InitStructure.NVIC_IRQChannel =TIM6_DAC_IRQn ;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
	TIM_TimeBaseStructure.TIM_Period = 1;
  TIM_TimeBaseStructure.TIM_Prescaler = 0;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);
	
	TIM_PrescalerConfig(TIM6,PrescalerValue, TIM_PSCReloadMode_Immediate);
	TIM_ITConfig(TIM6,TIM_IT_Update, ENABLE);
	TIM_Cmd(TIM6, ENABLE);
}

//===============================++=========================//
