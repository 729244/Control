/*
 * encoder.c
 *
 *  Created on: Dec 1, 2023
 *      Author: jonat
 */

#include "encoder.h"

static uint8_t p1_en1 = 0;
static uint8_t p2_en1 = 0;
static uint8_t p3_en1 = 0;
static uint8_t p4_en1 = 0;
static uint8_t p5_en1 = 0;
static uint8_t p6_en1 = 0;
static uint8_t p7_en1 = 0;
static uint8_t p8_en1 = 0;

static uint8_t p1_en2 = 0;
static uint8_t p2_en2 = 0;
static uint8_t p3_en2 = 0;
static uint8_t p4_en2 = 0;
static uint8_t p5_en2 = 0;
static uint8_t p6_en2 = 0;
static uint8_t p7_en2 = 0;
static uint8_t p8_en2 = 0;

static const uint8_t tabla_magica[128] =
{
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
		20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37,
		38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55,
		56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73,
		74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91,
		92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107,
		108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121,
		122, 123, 124, 125, 126, 127
};


uint8_t get_position(uint8_t p8, uint8_t p7, uint8_t p6,uint8_t p5, uint8_t p4, uint8_t p3, uint8_t p2, uint8_t p1)
{
	uint8_t dec_output = (p8*128)+(p7*64)+(p6*32)+(p5*16)+(p4*8)+(p3*4)+(p2*2)+p1;
	static uint8_t position = 0;

	if(dec_output <= 64)
	{
		position = pos_range_64(dec_output);
	}
	else if (dec_output <= 128)
	{
		position = pos_range_128(dec_output);
	}
	else if (dec_output <= 192)
	{
		position = pos_range_192(dec_output);
	}
	else
	{
		position = pos_range_255(dec_output);
	}
	return position;
}

uint8_t pos_range_64(uint8_t dec_output)
{
	uint8_t position;
	if(63 == dec_output)
	{
		position = tabla_magica[1];
	}
	if(62 == dec_output)
	{
		position = tabla_magica[2];
	}
	if(58 == dec_output)
	{
		position = tabla_magica[3];
	}
	if(56 == dec_output)
	{
		position = tabla_magica[4];
	}
	if(24 == dec_output)
	{
		position = tabla_magica[7];
	}
	if(8 == dec_output)
	{
		position = tabla_magica[8];
	}
	if(15 == dec_output)
	{
		position = tabla_magica[13];
	}
	if(47 == dec_output)
	{
		position = tabla_magica[14];
	}
	if(31 == dec_output)
	{
		position = tabla_magica[18];
	}
	if(29 == dec_output)
	{
		position = tabla_magica[19];
	}
	if(28 == dec_output)
	{
		position = tabla_magica[20];
	}
	if(12 == dec_output)
	{
		position = tabla_magica[23];
	}
	if(4 == dec_output)
	{
		position = tabla_magica[24];
	}
	if(36 == dec_output)
	{
		position = tabla_magica[25];
	}
	if(14 == dec_output)
	{
		position = tabla_magica[36];
	}
	if(46 == dec_output)
	{
		position = tabla_magica[37];
	}
	if(38 == dec_output)
	{
		position = tabla_magica[38];
	}
	if(6 == dec_output)
	{
		position = tabla_magica[39];
	}
	if(2 == dec_output)
	{
		position = tabla_magica[40];
	}
	if(18 == dec_output)
	{
		position = tabla_magica[41];
	}
	if(7 == dec_output)
	{
		position = tabla_magica[52];
	}
	if(23 == dec_output)
	{
		position = tabla_magica[53];
	}
	if(19 == dec_output)
	{
		position = tabla_magica[54];
	}
	if(3 == dec_output)
	{
		position = tabla_magica[55];
	}
	if(1 == dec_output)
	{
		position = tabla_magica[56];
	}
	if(9 == dec_output)
	{
		position = tabla_magica[57];
	}
	if(41 == dec_output)
	{
		position = tabla_magica[58];
	}
	if(32 == dec_output)
	{
		position = tabla_magica[104];
	}
	if(33 == dec_output)
	{
		position = tabla_magica[105];
	}
	if(37 == dec_output)
	{
		position = tabla_magica[106];
	}
	if(53 == dec_output)
	{
		position = tabla_magica[107];
	}
	if(61 == dec_output)
	{
		position = tabla_magica[108];
	}
	if(60 == dec_output)
	{
		position = tabla_magica[109];
	}
	if(49 == dec_output)
	{
		position = tabla_magica[118];
	}
	if(48 == dec_output)
	{
		position = tabla_magica[119];
	}
	if(16 == dec_output)
	{
		position = tabla_magica[120];
	}
	if(30 == dec_output)
	{
		position = tabla_magica[125];
	}
	return position;
}

uint8_t pos_range_128(uint8_t dec_output)
{
	uint8_t position;
	if(127 == dec_output)
	{
		position = tabla_magica[0];
	}
		if(72 == dec_output)
		{
			position = tabla_magica[9];
		}
		if(73 == dec_output)
		{
			position = tabla_magica[10];
		}
		if(77 == dec_output)
		{
			position = tabla_magica[11];
		}
		if(79 == dec_output)
		{
			position = tabla_magica[12];
		}
		if(92 == dec_output)
		{
			position = tabla_magica[21];
		}
		if(76 == dec_output)
		{
			position = tabla_magica[22];
		}

		if(82 == dec_output)
		{
			position = tabla_magica[42];
		}
		if(83 == dec_output)
		{
			position = tabla_magica[43];
		}
		if(71 == dec_output)
		{
			position = tabla_magica[51];
		}
		if(128 == dec_output)
		{
			position = tabla_magica[72];
		}
		if(84 == dec_output)
		{
			position = tabla_magica[88];
		}
		if(66 == dec_output)
		{
			position = tabla_magica[89];
		}
		if(74 == dec_output)
		{
			position = tabla_magica[90];
		}
		if(106 == dec_output)
		{
			position = tabla_magica[91];
		}
		if(122 == dec_output)
		{
			position = tabla_magica[92];
		}
		if(120 == dec_output)
		{
			position = tabla_magica[93];
		}
		if(121 == dec_output)
		{
			position = tabla_magica[94];
		}
		if(125 == dec_output)
		{
			position = tabla_magica[95];
		}
		if(98 == dec_output)
		{
			position = tabla_magica[102];
		}
		if(96 == dec_output)
		{
			position = tabla_magica[103];
		}
		if(126 == dec_output)
		{
			position = tabla_magica[113];
		}
		if(124 == dec_output)
		{
			position = tabla_magica[114];
		}
		if(116 == dec_output)
		{
			position = tabla_magica[115];
		}
		if(112 == dec_output)
		{
			position = tabla_magica[116];
		}
		if(113 == dec_output)
		{
			position = tabla_magica[117];
		}
		if(94 == dec_output)
		{
			position = tabla_magica[126];
		}
		if(95 == dec_output)
		{
			position = tabla_magica[127];
		}
		return position;
}

uint8_t pos_range_192(uint8_t dec_output)
{
	uint8_t position;
	if(164 == dec_output)
	{
		position = tabla_magica[26];
	}
	if(166 == dec_output)
	{
		position = tabla_magica[27];
	}
	if(167 == dec_output)
	{
		position = tabla_magica[28];
	}
	if(135 == dec_output)
	{
		position = tabla_magica[29];
	}
	if(151 == dec_output)
	{
		position = tabla_magica[30];
	}
	if(184 == dec_output)
	{
		position = tabla_magica[5];
	}
	if(152 == dec_output)
	{
		position = tabla_magica[6];
	}

	if(175 == dec_output)
	{
		position = tabla_magica[15];
	}
	if(191 == dec_output)
	{
		position = tabla_magica[16];
	}
	if(159 == dec_output)
	{
		position = tabla_magica[17];
	}
	if(143 == dec_output)
	{
		position = tabla_magica[34];
	}
	if(142 == dec_output)
	{
		position = tabla_magica[35];
	}
	if(169 == dec_output)
	{
		position = tabla_magica[59];
	}
	if(163 == dec_output)
	{
		position = tabla_magica[67];
	}
	if(131 == dec_output)
	{
		position = tabla_magica[68];
	}
	if(139 == dec_output)
	{
		position = tabla_magica[69];
	}
	if(137 == dec_output)
	{
		position = tabla_magica[70];
	}
	if(129 == dec_output)
	{
		position = tabla_magica[71];
	}
	if(132 == dec_output)
	{
		position = tabla_magica[73];
	}
	if(148 == dec_output)
	{
		position = tabla_magica[74];
	}
	if(192 == dec_output)
	{
		position = tabla_magica[87];
	}
	if(188 == dec_output)
	{
		position = tabla_magica[110];
	}
	if(190 == dec_output)
	{
		position = tabla_magica[111];
	}
	if(144 == dec_output)
	{
		position = tabla_magica[121];
	}
	if(146 == dec_output)
	{
		position = tabla_magica[122];
	}
	if(154 == dec_output)
	{
		position = tabla_magica[123];
	}
	if(158 == dec_output)
	{
		position = tabla_magica[124];
	}
	return position;
}

uint8_t pos_range_255(uint8_t dec_output)
{
	uint8_t position = 0;
	if(215 == dec_output)
	{
		position = tabla_magica[31];
	}
	if(223 == dec_output)
	{
		position = tabla_magica[32];
	}
	if(207 == dec_output)
	{
		position = tabla_magica[33];
	}
	if(211 == dec_output)
	{
		position = tabla_magica[44];
	}
	if(195 == dec_output)
	{
		position = tabla_magica[45];
	}
	if(203 == dec_output)
	{
		position = tabla_magica[46];
	}
	if(235 == dec_output)
	{
		position = tabla_magica[47];
	}
	if(239 == dec_output)
	{
		position = tabla_magica[48];
	}
	if(231 == dec_output)
	{
		position = tabla_magica[49];
	}
	if(199 == dec_output)
	{
		position = tabla_magica[50];
	}
	if(233 == dec_output)
	{
		position = tabla_magica[60];
	}
	if(225 == dec_output)
	{
		position = tabla_magica[61];
	}
	if(229 == dec_output)
	{
		position = tabla_magica[62];
	}
	if(245 == dec_output)
	{
		position = tabla_magica[63];
	}
	if(247 == dec_output)
	{
		position = tabla_magica[64];
	}
	if(243 == dec_output)
	{
		position = tabla_magica[65];
	}
	if(227 == dec_output)
	{
		position = tabla_magica[66];
	}
	if(212 == dec_output)
	{
		position = tabla_magica[75];
	}
	if(244 == dec_output)
	{
		position = tabla_magica[76];
	}
	if(240 == dec_output)
	{
		position = tabla_magica[77];
	}
	if(242 == dec_output)
	{
		position = tabla_magica[78];
	}
	if(250 == dec_output)
	{
		position = tabla_magica[79];
	}
	if(251 == dec_output)
	{
		position = tabla_magica[80];
	}
	if(249 == dec_output)
	{
		position = tabla_magica[81];
	}
	if(241 == dec_output)
	{
		position = tabla_magica[82];
	}
	if(209 == dec_output)
	{
		position = tabla_magica[83];
	}
	if(193 == dec_output)
	{
		position = tabla_magica[84];
	}
	if(197 == dec_output)
	{
		position = tabla_magica[85];
	}
	if(196 == dec_output)
	{
		position = tabla_magica[86];
	}
	if(253 == dec_output)
	{
		position = tabla_magica[96];
	}
	if(252 == dec_output)
	{
		position = tabla_magica[97];
	}
	if(248 == dec_output)
	{
		position = tabla_magica[98];
	}
	if(232 == dec_output)
	{
		position = tabla_magica[99];
	}
	if(224 == dec_output)
	{
		position = tabla_magica[100];
	}
	if(226 == dec_output)
	{
		position = tabla_magica[101];
	}
	if(254 == dec_output)
	{
		position = tabla_magica[112];
	}
	return position;
}

void get_bits (void)
{
	p1_en1 = gpio_get_pin(GPIOB, B18_P1);
	p2_en1 = gpio_get_pin(GPIOB, B19_P2);
	p3_en1 = gpio_get_pin(GPIOB, B10_P3);
	p4_en1 = gpio_get_pin(GPIOB, B11_P4);
	p5_en1 = gpio_get_pin(GPIOC, C11_P5);
	p6_en1 = gpio_get_pin(GPIOC, C10_P6);
	p7_en1 = gpio_get_pin(GPIOB, B20_P7);
	p8_en1 = gpio_get_pin(GPIOD, D1_P8);

	p1_en2 = gpio_get_pin(GPIOC, C3_P1);
	p2_en2 = gpio_get_pin(GPIOC, C2_P2);
	p3_en2 = gpio_get_pin(GPIOA, A2_P3);
	p4_en2 = gpio_get_pin(GPIOB, B23_P4);
	p5_en2 = gpio_get_pin(GPIOA, A1_P5);
	p6_en2 = gpio_get_pin(GPIOB, B9_P6);
	p7_en2 = gpio_get_pin(GPIOB, C17_P7);
	p8_en2 = gpio_get_pin(GPIOB, C16_P8);
}

uint8_t read_encoder(uint8_t which_enc)
{
	get_bits();
	uint8_t position = 0;
	if (0 == which_enc)
	{
		position = get_position(p1_en1, p2_en1, p3_en1, p4_en1, p5_en1, p6_en1, p7_en1, p8_en1);
	}
	if (1 == which_enc)
	{
		position = get_position(p1_en2, p2_en2, p3_en2, p4_en2, p5_en2, p6_en2, p7_en2, p8_en2);
	}
	return position;
}
