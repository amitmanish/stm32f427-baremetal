/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "uart_driver.h"

int main(void)
{


	SystemCoreClockUpdate();

	uart_init();

    //Trying to send some data now
	uint32_t data = 0xAD;
	while(1){
		USART1->DR = (uint32_t)data;
		while(!(USART1->SR & (0x00000040)));
	}
}
