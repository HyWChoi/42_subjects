#include "push_swap_merge.h"
// divide from asc
// divide from desc
// merge from asc
// merge from desc

element	find_max(t_deque *dq, int size)
{
	element	max;
	int	i;

	i = 1;
	max = dq->data[i % size];
	while (i != dq->rear)
	{
		if (max < dq->data[(i + 1) % size])
			max = dq->data[(i + 1) % size];
		i = (i + 1) % size;
	}

	return (max);
}
/*
void	devide_three_uions_from_asc(t_deque *dq_a, t_deque *dq_b, int size)
{
	// asc
	// desc
	// asc
}

void	devide_three_uions_from_desc(t_deque *dq_a, t_deque *dq_b, int size)
{
	// asc
	// asc
	// desc
}

	 * 1. find the max number in the dqueue
	 * 2. find the index of the max number
	 * 3. rotate the dqueue until the max number is on the top
	 * 4. push the max number to the dqueue b
	 * 5. repeat the 1~4 until the size of the dqueue a is 3

//plz, make the function that make the ascending order in the dqueue that has the random numbers that is not sorted and user input the size of the dqueue
*/
void	push_asc_a_to_b(t_deque *dq_a, t_deque *dq_b, int size)
{

	element max;
	int max_index;
	int i;

	i = 0;
	max = find_max;
	//size만큼 순회를 돌면서 최대값을 찾은 뒤 올림
	//size만큼 다 순회를 돌면서 배열에 넘기면 GOOD!
}
