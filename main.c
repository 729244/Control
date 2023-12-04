
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_debug_console.h"
#include "I2C.h"
#include "pit.h"
#include "NVIC.h"
#include "GPIO.h"
#include "encoder.h"

int main(void) {
	i2c_pin_init();
	i2c_config();
	pit_init();
	gpio_init();

	NVIC_global_enable_interrupts;

	uint8_t data[2] = {0, 0};
	uint8_t address = 1;
	uint8_t data_size = 2;
	int16_t voltage = 0;
	uint16_t encoder_1 = 0;

	int16_t voltage_ref = 0;
	uint16_t encoder_1_ref = 0;

	encoder_1_ref = read_encoder(0);

    while(1) {
    		status_t status;
    		status = i2c_read(0x40, data, data_size, address, 1);
    		voltage =  (data[0] << 8) | (data[1]);
    		encoder_1 = read_encoder(0);

    		if(encoder_1_ref != encoder_1)
    		{
    			voltage_ref = voltage;
    			while(1){}
    		}
    }
    return 0 ;
}
