
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_def.h"

#include "stm_gpio.h"
#include "main.h"

extern stm_gpio_ret gpio_set_pulse_pin (void)
{
	HAL_GPIO_WritePin(MOTOR_PUL_GPIO_Port, MOTOR_PUL_Pin, GPIO_PIN_SET);
	return STM_GPIO_RET_OK;
}

extern stm_gpio_ret gpio_clear_pulse_pin (void)
{
	HAL_GPIO_WritePin(MOTOR_PUL_GPIO_Port, MOTOR_PUL_Pin, GPIO_PIN_RESET);
	return STM_GPIO_RET_OK;
}



