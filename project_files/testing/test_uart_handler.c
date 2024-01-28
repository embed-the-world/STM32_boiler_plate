
#include <stdio.h>

#include "test_uart_handler.h"
#include "uart_handler.h"

int main()
{
	int counter = 0;
	int elements_in_send_buffer = 0;
	int expected_number_of_elements_in_buffer = 0;
	uart_handler_ret return_value;
	uart_handler_ret expected_return;

	expected_return = UART_HANDLER_RET_OK;
	/* send overflow */
	for(counter = 0; counter <= MAX_QUEUE_ITEMS; counter++)
	{
		elements_in_send_buffer = uart_handler_get_number_of_messages_in_queue();
		if(expected_number_of_elements_in_buffer != elements_in_send_buffer)
		{
			printf("error in number of elements in buffer!\n"\
				"expected:    %d\n" \
				"read number: %d\n", \
				expected_number_of_elements_in_buffer, \
				elements_in_send_buffer);
		}
		if(counter == MAX_QUEUE_ITEMS)
		{
			expected_return = UART_HANDLER_RET_QUEUE_FULL;
		}
		return_value = uart_send_message("hi", 3);
		expected_number_of_elements_in_buffer++;
		if(return_value != expected_return)
		{
			printf("Error in testing queue overflow! item: %d\n", counter);
			break;
		}
	}
	printf("end\n");
	return 0;
}



