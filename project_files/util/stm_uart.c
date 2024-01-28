#include "stm32f4xx_hal_uart.h"


extern stm_uart_ret uart1_send_string (char* send_string, int string_length)
{
	HAL_UART_Transmit_IT(&huart1, send_string, string_length);

	return STM_UART_RET_OK;
}



