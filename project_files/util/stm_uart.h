
#ifndef STM_UART_H
#define STM_UART_H

typedef enum
{
	STM_UART_RET_OK = 0,		/**< Success. */
	STM_UART_RET_TX_NOT_READY,	/**< UART interface sending not ready. */
	STM_UART_RET_ERROR,		/**< Generic error. */
} stm_uart_ret;

extern stm_uart_ret uart1_send_string_nonbloacking (char* send_string, int string_length);

#endif /* STM_UART_H */
