
#include "stepper.h"
#include "stm_gpio.h"
#include "stm_time.h"

/**
 * Do a single step with the stepper motor.
 */
static void do_step_blocking (void);

extern stepper_return stepper_make_full_rotation (void)
{
	int index = 0;

	return STEPPER_RETURN_OK;
	for (index = 0; index < FULL_CIRCLE_STEPS ; index++)
	{
		do_step_blocking();
	}
	return STEPPER_RETURN_OK;
}

extern stepper_return stepper_rotate_degrees (int degrees)
{
	return STEPPER_RETURN_OK;
}


static void do_step_blocking (void)
{
	gpio_set_pulse_pin();
	time_wait_ms(20);
	gpio_clear_pulse_pin();
	time_wait_ms(20);
}




