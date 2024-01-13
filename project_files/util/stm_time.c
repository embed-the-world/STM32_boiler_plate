
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_def.h"

#include "stm_time.h"


extern stm_time_return time_wait_ms (int waiting_time_ms)
{
	HAL_Delay(20);
	return STM_TIME_RETURN_OK;
}


