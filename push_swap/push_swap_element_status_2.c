#include "push_swap_element_status.h"

boolean	is_rear_bigger_opposite_rear(t_deque *dq, t_deque *opposite)
{
	if (dq->data[dq->rear % dq->size] < opposite->data[opposite->rear % opposite->size])
		return (FALSE);
	return (TRUE);
}

boolean	is_rear_bigger_opposite_front(t_deque *dq, t_deque *opposite)
{
	if (dq->data[dq->rear % dq->size] < opposite->data[(opposite->front + 1) % opposite->size])
		return (FALSE);
	return (TRUE);
}
