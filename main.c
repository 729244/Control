
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_debug_console.h"
#include "I2C.h"
#include "ina219.h"

int main(void) {
	i2c_pin_init();
	i2c_config();

    while(1) {
    	float current = INA219_get_current(0);
    }
    return 0 ;
}
