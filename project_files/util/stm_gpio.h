
#ifndef STM_GPIO
#define STM_GPIO

typedef enum
{
	STM_GPIO_RET_OK = 1,	/**< Success. */
	STM_GPIO_RET_ERROR,	/**< Command failed. */
}stm_gpio_ret;

extern stm_gpio_ret gpio_set_pulse_pin (void);
extern stm_gpio_ret gpio_clear_pulse_pin (void);

#endif /* STM_GPIO */

