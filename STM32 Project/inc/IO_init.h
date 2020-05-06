#ifndef _IO_init_H
#define _IO_init_H

#include "STM32F4xx.h"

void Temp_SPI_init(void);
void PWM_Init(void);
void Sample_Timer_init(void);
void user_bt_init(void);

//////////////////////////////////////////////////
///////// Defines const here///////////////////
//////////////////////////////////////////////////


//Timer6_Sample_Time 
#define			Sample_Prescalered_clock		7000000
#define			Sample_Period								1


#endif
