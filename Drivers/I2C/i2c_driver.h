/*
 * i2c_driver.h
 *
 *  Created on: Sep 1, 2021
 *      Author: lucifer
 */

#ifndef __I2C_DRIVER__
#define __I2C_DRIVER__

#include "stm32f4xx.h"

#define MPU_ADDRESS (0x68<<1)
#define MPU_ADDRESS_READ (0x68<<1|0x1)
#define WHO_AM_I_REG 0x75
#define PWR_1_REG 0x68

enum i2c_mode{
	i2c_mode_write = 0,
	i2c_mode_read = 1,
};

void i2c_int(void);

void send_start(void);

void send_stop(void);

void send_address(uint8_t );

void i2c_send_byte(uint8_t);

uint8_t i2c_receive_byte(void);

void i2c_send_data(uint8_t);

uint8_t i2c_receive_data(void);

#endif
