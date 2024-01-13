
#ifndef STM_TIME_H
#define STM_TIME_H

typedef enum
{
	STM_TIME_RETURN_OK = 0, /**< Success. */
	STM_TIME_RETURN_ERROR,	/**< Generic error. */
} stm_time_return;

extern stm_time_return time_wait_ms (int waiting_time_ms);

#endif /* STM_TIME_H */
