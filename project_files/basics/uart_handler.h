
#ifndef UART_HANDLER_H
#define UART_HANDLER_H

#define MAX_QUEUE_ITEMS (10)	/* Max number of buffered message items. */

typedef enum
{
	UART_HANDLER_RET_OK = 0,	/**< Success. */
	UART_HANDLER_RET_ERROR,		/**< Generic error. */
	UART_HANDLER_RET_NO_MEM,	/**< Cannot allocate memory. */
	UART_HANDLER_RET_QUEUE_FULL,	/**< Queue reached maximum number of elements. */
} uart_handler_ret;

extern uart_handler_ret uart_send_message (char* message, int message_length);

extern int uart_handler_get_number_of_messages_in_queue (void);

#endif /* UART_HANDLER_H */

