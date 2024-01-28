
#ifndef STM_GPIO_H
#define STM_GPIO_H

typedef enum
{
	STM_GPIO_RET_OK = 1,	/**< Success. */
	STM_GPIO_RET_ERROR,	/**< Command failed. */
}stm_gpio_ret;

extern stm_gpio_ret gpio_set_pulse_pin (void);
extern stm_gpio_ret gpio_clear_pulse_pin (void);
extern stm_gpio_ret gpio_activate_user_led (void);
extern stm_gpio_ret gpio_deactivate_user_led (void);

#endif /* STM_GPIO_H */

