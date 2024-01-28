
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "uart_handler.h"


struct message_item
{
	char* message_string;
	struct message_item* next_message;
};

struct message_item_queue_head
{
	struct message_item* first_message;
	int number_of_elements;
} message_item_head = {NULL, 0};

/* PROTOTYPES */

static uart_handler_ret enqueue_message (char* message, int message_length);
static uart_handler_ret attach_item_to_end_of_queue (struct message_item new_item);

/* EXTERN FUNC ************************************/

extern uart_handler_ret uart_send_message (char* message, int message_length)
{
	enqueue_message(message, message_length);
	return UART_HANDLER_RET_OK;
}

extern int uart_handler_get_number_of_messages_in_queue (void)
{
	return message_item_head.number_of_elements;
}

/* STATIC FUNC ************************************/

static uart_handler_ret enqueue_message (char* message, int message_length)
{
	struct message_item new_message;
	new_message.message_string = malloc(message_length);
	if(NULL == new_message.message_string)
		return UART_HANDLER_RET_NO_MEM;
	memcpy(new_message.message_string, message, message_length);
	return attach_item_to_end_of_queue(new_message);
}

static uart_handler_ret attach_item_to_end_of_queue (struct message_item new_item)
{
	struct message_item* queue_item = NULL;
	int ko_counter = 0;
	if (NULL == message_item_head.first_message)
	{
		message_item_head.first_message = malloc(sizeof(struct message_item));
		if(NULL == message_item_head.first_message)
			return UART_HANDLER_RET_NO_MEM;
		memcpy(message_item_head.first_message, &new_item, sizeof(struct message_item));
		message_item_head.number_of_elements++;
		return UART_HANDLER_RET_ERROR;
	}
	/* first message is not empty, attach to end of queue. */
	queue_item = message_item_head.first_message;
	while(ko_counter < (MAX_QUEUE_ITEMS - 1) )
	{
		ko_counter++;
		if(NULL == queue_item->next_message)
		{
			/* end of queue found! */
			break;
		}
		queue_item = queue_item->next_message;
	}
	if(MAX_QUEUE_ITEMS == ko_counter)
		return UART_HANDLER_RET_QUEUE_FULL;
	message_item_head.first_message = malloc(sizeof(struct message_item));
	if(NULL == message_item_head.first_message)
		return UART_HANDLER_RET_NO_MEM;
	memcpy(message_item_head.first_message, &new_item, sizeof(struct message_item));
	message_item_head.number_of_elements++;
	return UART_HANDLER_RET_OK;
}

