
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_debug_console.h"
#include "I2C.h"

int main(void) {
	i2c_pin_init();
	i2c_config();

	uint8_t data[2] = {0, 0};
	uint8_t address = 1;
	uint8_t data_size = 2;

    while(1) {
    	status_t status;
    	status = i2c_read(0x40, data, data_size, address, 1);
    	int16_t voltage =  (data[0] << 8) | (data[1]);
    	float current = voltage * 0.1;
    }
    return 0 ;
}
