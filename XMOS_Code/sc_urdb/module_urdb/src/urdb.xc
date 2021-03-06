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

void urdb_init(unsigned char xbee_mode)
{
	// Allocate chanend resources for the IO servers/other threads and save the resource IDs
	par
	{
		on stdcore[IMU_I2C_CORE] : imu_i2c_req_ch = _getChanEnd();
		on stdcore[IMU_I2C_CORE] : imu_i2c_service_ch = _getChanEnd();
		on stdcore[SPI_CORE] : spi_req_ch = _getChanEnd();
		on stdcore[SPI_CORE] : spi_service_ch = _getChanEnd();
		on stdcore[STM32_CORE] : stm32_req_ch = _getChanEnd();
		on stdcore[STM32_CORE] : stm32_service_ch = _getChanEnd();
		on stdcore[XBEE_CORE] : xbee_req_ch = _getChanEnd();
		on stdcore[XBEE_CORE] : xbee_service_ch = _getChanEnd();
		on stdcore[PWM_CORE] : pwm_chanend = _getChanEnd();
		on stdcore[NAVIGATION_CORE] : navigation_chanend = _getChanEnd();
	}


	// Check for successful allocation of chanends
	if(!imu_i2c_req_ch || !imu_i2c_service_ch || !spi_req_ch || !spi_service_ch ||
			!stm32_req_ch || !stm32_service_ch || !pwm_chanend ||
			!navigation_chanend || !xbee_req_ch || !xbee_service_ch)
		return;

	// Initialize clocks
	par
	{
		on stdcore[0] : ref0 = XS1_CLKBLK_1;
		on stdcore[1] : ref1 = XS1_CLKBLK_1;
	}

	// Execute all URDB threads
	if(xbee_mode == XBEE_MODE_API)
	{
		par
		{
			on stdcore[IMU_I2C_CORE] : i2c_server(&imu_i2c_req_ch, &imu_i2c_service_ch);
			on stdcore[SPI_CORE] : spi_server(&spi_req_ch, &spi_service_ch);
			on stdcore[STM32_CORE] : stm32_uart_server(&stm32_req_ch, &stm32_service_ch);
			on stdcore[PWM_CORE] : pwmSingleBitPort(pwm_chanend, ref1, pwm_port,
				    PWM_NUM_PORTS, PWM_RESOLUTION, PWM_TIMESTEP, 1);
			// on stdcore[NAVIGATION_CORE] : Navigation thread
			on stdcore[XBEE_CORE] : xbee_api_server(&xbee_req_ch, &xbee_service_ch);
		}
	}
	else if(xbee_mode == XBEE_MODE_TRANSPARENT)
	{
		par
		{
			on stdcore[IMU_I2C_CORE] : i2c_server(&imu_i2c_req_ch, &imu_i2c_service_ch);
			on stdcore[SPI_CORE] : spi_server(&spi_req_ch, &spi_service_ch);
			on stdcore[STM32_CORE] : stm32_uart_server(&stm32_req_ch, &stm32_service_ch);
			on stdcore[PWM_CORE] : pwmSingleBitPort(pwm_chanend, ref1, pwm_port,
				    PWM_NUM_PORTS, PWM_RESOLUTION, PWM_TIMESTEP, 1);
			// on stdcore[NAVIGATION_CORE] : Navigation thread
			on stdcore[XBEE_CORE] : xbee_transparent_server(&xbee_req_ch, &xbee_service_ch);
		}
	}
	else
	{
		par
		{
			on stdcore[IMU_I2C_CORE] : i2c_server(&imu_i2c_req_ch, &imu_i2c_service_ch);
			on stdcore[SPI_CORE] : spi_server(&spi_req_ch, &spi_service_ch);
			on stdcore[STM32_CORE] : stm32_uart_server(&stm32_req_ch, &stm32_service_ch);
			on stdcore[PWM_CORE] : pwmSingleBitPort(pwm_chanend, ref1, pwm_port,
				    PWM_NUM_PORTS, PWM_RESOLUTION, PWM_TIMESTEP, 1);
			// on stdcore[NAVIGATION_CORE] : Navigation thread
		}
	}

}
