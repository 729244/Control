/*
*	@file I2C.h
*
*	@Authors Carlos Fernando Orozco Cuetara
*			 Jonathan Azahel Trujillo Zuno
*
*	@brief: This program controls the interactions between I2C.h and other layers
*
*/

#ifndef I2C_H_
#define I2C_H_

#include "fsl_i2c.h"
#include "fsl_port.h"
#include "fsl_common.h"
#include "fsl_clock.h"


#define I2C_MASTER_CLK_SRC          I2C0_CLK_SRC
#define I2C_MASTER_CLK_FREQ         CLOCK_GetFreq(I2C0_CLK_SRC)
#define I2C0_MASTER_BASEADDR 		I2C0
#define WAIT_TIME                   10U

#define I2C_DEVICE_ADDR		0X1U
#define I2C_SLAVE_SUBADDR_S	0X1U

#define I2C_BAUDRATE               100000U
#define I2C_WRITE_DATA_LENGTH      1U
#define I2C_READ_DATA_LENGTH       6U

#define SCL 2U
#define SDA 3U


void i2c_pin_init (void);
void i2c_config(void);
status_t i2c_write(uint8_t,  uint8_t *, uint32_t, uint32_t, uint8_t);
status_t i2c_read(uint8_t,  uint8_t *, uint32_t, uint32_t, uint8_t);

#endif /* I2C_H_ */
