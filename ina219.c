/*
 * ina219.c
 *
 *  Created on: 2 dic 2023
 *      Author: Fernando
 */


#include "ina219.h"

float INA219_get_current(uint8_t ina){
	status_t status;
	uint8_t address;
	uint8_t data[2] = {0, 0};
	if(0 == ina){
		address = INA0_ADD;
	}
	else{
		address = INA1_ADD;
	}
	status = i2c_read(address, data, READ_BYTES, SHUNT_ADD, ADD_BYTES);
	if(0 != status){
		return 0;
	}
	int16_t voltage =  (data[0] << 8) | (data[1]);
	float current = voltage * 0.1;
	return current;
}
