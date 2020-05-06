#include "delay.h"
#include "IO_init.h"
#include "IT.h"
#include "Function.h"
uint16_t count;
uint32_t data;
int32_t data1;
double data2;

int main()
{
		int i,j;

	Temp_SPI_init();
	SystemCoreClockUpdate();                      
  if (SysTick_Config(SystemCoreClock / 1000)) 
		{ 
    while (1);                                  
		}
	//==============================================//

		Sample_Timer_init();

  //==============================================//

		GPIO_SetBits(GPIOB,GPIO_Pin_13);
		j=count;
		while ((count-j)<=1600);
		GPIO_ResetBits(GPIOB,GPIO_Pin_13);

  //==============================================//		
	while(1)
	{
		if (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14)==Bit_SET)
		{
			j=count;
			while ((count-j)<=38)
			{
				if(((int)(count-j))<0)
				{
					count=  38-(0xFFFFFFFF-j)-count;
					j=0;
				}
			
			}
		for (i=23; i>=0; i--)
            {
                    GPIO_SetBits(GPIOB, GPIO_Pin_13);				
                    if (GPIO_ReadInputDataBit( GPIOB, GPIO_Pin_14))   
                              data |= (1 << i);
                   GPIO_ResetBits(GPIOB, GPIO_Pin_13);
										
										
            }
		
if(data<=0x7FFFFF)
	data1=data;
else
	data1=-(int)(((~data)&0xFFFFFF)+1);
data2=(double)(data1)*3/0x7FFFFF;
data=0;						
		
		}
	
	
			
	}
	
	

}















