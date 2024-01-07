#include "push_swap.h"
//Reference from https://blog.naver.com/sooftware/221516440423
void	init_deque(t_deque *dq, size_t size)
{
	dq->data = (element*)malloc(sizeof(element) * size);
	dq->front = 0;
	dq->rear = 0;
}

boolean is_empty(t_deque *dq)
{
	return (dq->front == dq->rear);
}

boolean	is_full(t_deque *dq, size_t size)
{
	return ((dq->rear + 1) % size == dq->front);
	// deque의 size가 5일 때, rear가 한바퀴 모두 돌아 size로 나눴을 때, 1이 되면 front에 도달했다고 볼 수 있음
}

element get_rear(t_deque *dq)
{
	if (is_empty(dq))
	{
		ft_printf("que is empty\n");
		return (ERROR);
	}
	return (dq->data[dq->rear]);
}

element	get_front(t_deque *dq, size_t size)
{
	if (is_empty(dq))
	{
		ft_printf("que is empty\n");
		return (ERROR);
	}
	return (dq->data[(dq->front + 1) % size]);
}

void	insert_rear(t_deque *dq, size_t size)
{
}
