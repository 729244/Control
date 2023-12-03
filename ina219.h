/*
 * ina219.h
 *
 *  Created on: 2 dic 2023
 *      Author: Fernando
 */

#ifndef INA219_H_
#define INA219_H_

#include "I2C.h"
#include "stdint.h"

#define INA0_ADD	0x40
#define INA1_ADD	0x41
#define ADD_BYTES	1
#define READ_BYTES 	2
#define SHUNT_ADD	1

float INA219_get_current(uint8_t);

#endif /* INA219_H_ */
