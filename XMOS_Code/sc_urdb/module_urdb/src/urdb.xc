/**
 * urdb.xc
 *
 *  @date 1/1/2012
 *  @author jbaker
 */

#include "urdb.h"
#include "io_servers.h"
#include "xlog_support.h"

#define PWM_RESOLUTION 256
#define PWM_PERIOD (RESOLUTION*20)
#define PWM_NUM_PORTS 9
#define PWM_TIMESTEP 10

void urdb_init()
{
	// Allocate chanend resources for the IO servers/other threads and save the resource IDs
	par
	{
		on stdcore[I2C_CORE] : i2c_chanend = _getChanEnd();
		on stdcore[SPI_CORE] : spi_chanend = _getChanEnd();
		on stdcore[STM32_CORE] : stm32_uart_chanend = _getChanEnd();
		on stdcore[PWM_CORE] : pwm_chanend = _getChanEnd();
		on stdcore[NAVIGATION_CORE] : navigation_chanend = _getChanEnd();
	}

	// Check for successful allocation of chanends
	if(!i2c_chanend || !spi_chanend || !stm32_uart_chanend || !pwm_chanend || !navigation_chanend)
		return;

	// Initialize clocks
	par
	{
		on stdcore[0] : ref0 = XS1_CLKBLK_1;
		on stdcore[1] : ref1 = XS1_CLKBLK_1;
	}

	// Execute all URDB threads
	par
	{
		on stdcore[I2C_CORE] : i2c_server(&i2c_chanend);
		on stdcore[SPI_CORE] : spi_server(&spi_chanend);
		on stdcore[STM32_CORE] : stm32_uart_server(&stm32_uart_chanend);
		on stdcore[PWM_CORE] : pwmSingleBitPort(pwm_chanend, ref1, pwm_ports,
			    PWM_NUM_PORTS, PWM_RESOLUTION, PWM_TIMESTEP, 1);
		// on stdcore[NAVIGATION_CORE] : Navigation thread
	}
}
