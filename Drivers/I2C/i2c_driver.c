/*
 * i2c_driver.c
 *
 *  Created on: Sep 1, 2021
 *      Author: lucifer
 */
#include "i2c_driver.h"
#include "uart_driver.h"






void i2c_int(void){

//Enable clock for I2C controller and SCL(PB6) and SDA(PB7) of I2C1
RCC->APB1ENR |= (uint32_t)(0x1<<21);
RCC->APB2ENR |= (uint32_t)(0x1<<3 | 0x1<<0);

I2C1->CR1 &= ~(uint32_t)0x1;
//Configure SCL(PB6) and SDA(PB7)
GPIOB->CRL |= (uint32_t)0xFF000000;
//Software reset for I2C controller
I2C1->CR1 |= (uint32_t)(0x1<<15);
for(uint32_t i=0;i<500;i++);
I2C1->CR1 &= ~(uint32_t)(0x1<<15);
//Configure I2C controller
/* 1) Disable I2C controller */
I2C1->CR1 &= ~(uint32_t)0x1;
/* 1) configure I2C controller input clock i.e PCLK clock */
I2C1->CR2 |= (uint32_t)0x20;
I2C1->CCR |= (uint32_t)0xA0;
I2C1->TRISE |= (uint32_t)0x21;

/*Enable I2C controller */
I2C1->CR1 |= (uint32_t)0x1;

}

void send_start(void){
while((I2C1->SR2&(0x1<<1)));
I2C1->CR1 |= (uint32_t)0x100;
while(!(I2C1->SR1&(0x1<<0)));
}

void send_stop(void){
I2C1->CR1 |= (uint32_t)0x200;
uint16_t temporary = I2C1->SR1;
}

void send_address(uint8_t address){
I2C1->DR = address;
while(!(I2C1->SR1&(0x1<<1)));
uint16_t temp = I2C1->SR1 | I2C1->SR2;
}

void i2c_send_byte(uint8_t data){
	while(!(I2C1->SR1&(0x1<<7)));
	I2C1->DR = data;
	while(!(I2C1->SR1&(0x1<<2)));

}

uint8_t i2c_receive_byte(){
uint8_t data;
while(!(I2C1->SR1&(0x1<<6)));
data = I2C1->DR;
return data;
}

void i2c_send_data(uint8_t data){
	send_start();
	send_data("Start sent");
	send_byte('\n');
	send_byte('\r');
	send_address(MPU_ADDRESS);
	send_data("Slave address sent");
		send_byte('\n');
		send_byte('\r');
	i2c_send_byte(data);
	send_stop();
}

uint8_t i2c_receive_data(void){
	uint8_t data;
	//Disable the ACK
	I2C1->SR1 &= ~(0x1<<10);
	send_start();
	send_address(MPU_ADDRESS_READ);
	send_data("Slave address for byte read sent");
			send_byte('\n');
			send_byte('\r');
	data = i2c_receive_byte();
	send_data("byte read");
			send_byte('\n');
			send_byte('\r');
	send_stop();
	return data;
}


