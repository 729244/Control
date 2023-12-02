/*
*	@file I2C.c
*
*	@Authors Carlos Fernando Orozco Cuetara
*			 Jonathan Azahel Trujillo Zuno
*
*	@brief: This program controls the I2C communication protocol
*
*/
#include "i2c.h"
#include "fsl_clock.h"

void i2c_pin_init (void)
{
	CLOCK_EnableClock(kCLOCK_PortB);

	const port_pin_config_t portb_pin3_config = {/* Internal pull-up resistor is enabled */
	                                                   kPORT_PullUp,
	                                                   /* Fast slew rate is configured */
	                                                   kPORT_FastSlewRate,
	                                                   /* Passive filter is disabled */
	                                                   kPORT_PassiveFilterDisable,
	                                                   /* Open drain is enabled */
	                                                   kPORT_OpenDrainEnable,
	                                                   /* Low drive strength is configured */
	                                                   kPORT_LowDriveStrength,
	                                                   /* Pin is configured as I2C0_SCL */
	                                                   kPORT_MuxAlt2,
	                                                   /* Pin Control Register fields [15:0] are not locked */
	                                                   kPORT_UnlockRegister};
	const port_pin_config_t portb_pin2_config = {/* Internal pull-up resistor is enabled */
	                                                   kPORT_PullUp,
	                                                   /* Fast slew rate is configured */
	                                                   kPORT_FastSlewRate,
	                                                   /* Passive filter is disabled */
	                                                   kPORT_PassiveFilterDisable,
	                                                   /* Open drain is enabled */
	                                                   kPORT_OpenDrainEnable,
	                                                   /* Low drive strength is configured */
	                                                   kPORT_LowDriveStrength,
	                                                   /* Pin is configured as I2C0_SCL */
	                                                   kPORT_MuxAlt2,
	                                                   /* Pin Control Register fields [15:0] are not locked */
	                                                   kPORT_UnlockRegister};
	 /* PORTB (pin 2) is configured as I2C0_SCL */
	 PORT_SetPinConfig(PORTB, SCL, &portb_pin3_config);
	 /* PORTB (pin 3) is configured as I2C0_SDA */
	 PORT_SetPinConfig(PORTB, SDA, &portb_pin2_config);
}

void i2c_config(void)
{
	uint32_t sourceClock;
	i2c_master_config_t masterConfig;

	I2C_MasterGetDefaultConfig(&masterConfig);

	masterConfig.baudRate_Bps = I2C_BAUDRATE;
	sourceClock = I2C_MASTER_CLK_FREQ;

	I2C_MasterInit(I2C0_MASTER_BASEADDR, &masterConfig, sourceClock);
}


status_t i2c_write(uint8_t slave_addr,  uint8_t * tx_buffer, uint32_t bytes_to_write, uint32_t address, uint8_t address_size)
{
	status_t status;
	i2c_master_transfer_t masterXfer;
	masterXfer.slaveAddress   = slave_addr;
	masterXfer.direction      = kI2C_Write;
	masterXfer.subaddress     = address;
	masterXfer.subaddressSize = address_size;
	masterXfer.data           = tx_buffer;
	masterXfer.dataSize       = bytes_to_write;
	masterXfer.flags          = kI2C_TransferDefaultFlag;

	status = I2C_MasterTransferBlocking(I2C0_MASTER_BASEADDR, &masterXfer);

	return status;
}

status_t i2c_read(uint8_t slave_addr,  uint8_t * rx_buffer, uint32_t bytes_to_read, uint32_t address, uint8_t address_size)
{
	status_t status;
	i2c_master_transfer_t masterXfer;
	masterXfer.slaveAddress   = slave_addr;
	masterXfer.direction      = kI2C_Read;
	masterXfer.subaddress     = address;
	masterXfer.subaddressSize = address_size;
	masterXfer.data           = rx_buffer;
	masterXfer.dataSize       = bytes_to_read;
	masterXfer.flags          = kI2C_TransferDefaultFlag;

	status = I2C_MasterTransferBlocking(I2C0_MASTER_BASEADDR, &masterXfer);

	return status;
}
