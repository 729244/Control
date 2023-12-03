/*
 * encoder.h
 *
 *  Created on: Dec 1, 2023
 *      Author: jonat
 */

#ifndef ENCODER_H_
#define ENCODER_H_

#include <stdint.h>
#include "GPIO.h"

typedef enum
{
	one,
	two,
	three,
	four,
	five,
	six,
	seven,
	eight
}pos_bit_t;

#define EVEN 0
#define ODD  1

uint8_t get_position (uint8_t p8, uint8_t p7, uint8_t p6,uint8_t p5, uint8_t p4, uint8_t p3, uint8_t p2, uint8_t p1);
uint8_t pos_range_64(uint8_t dec_output);
uint8_t pos_range_128(uint8_t dec_output);
uint8_t pos_range_192(uint8_t dec_output);
uint8_t pos_range_255(uint8_t dec_output);
uint8_t read_encoder(uint8_t which_enc);
void get_bits (void);
#endif /* ENCODER_H_ */
