
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_def.h"
#include "stm32f4xx_hal_gpio.h"

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

extern stm_gpio_ret gpio_activate_user_led (void)
{
	HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, GPIO_PIN_SET);
	return STM_GPIO_RET_OK;
}

extern stm_gpio_ret gpio_deactivate_user_led (void)
{
	HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, GPIO_PIN_RESET);
	return STM_GPIO_RET_OK;
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(USER_BUTTON_Pin == GPIO_Pin)
		gpio_activate_user_led();
}

