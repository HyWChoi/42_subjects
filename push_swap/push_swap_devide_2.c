#include "push_swap_devide.h"

int	count_moves_with_value(t_deque *dq, int value_index)
{
	int ra;
	int rra;
	int sa;
	int pb;

	pb = 0;
	sa = 1;
	ra = 2;
	rra = 3;
	if (value_index == (dq->front + 1) % dq->size)
		return (pb);
	else if (value_index == (dq->front + 2) % dq->size)
		return (sa);
	else if (is_closer_front(dq, value_index))
		return (ra);
	else
		return (rra);
}


void	make_asc_2_b(t_deque *dq_a, t_deque *dq_b, int amt)
{
	int	i;
	int	move;
	int	max_index;
	int max;
	int	count;

	i = 0;
	count = 0;
	if (is_sorted_desc1(dq_a, amt))
		while (amt-- > 0)
			pb(dq_a, dq_b,dq_a->size);
	while (i < amt)
	{
		if (i == 0)
		{
			max_index = get_max_index(dq_a, amt - i);
			move = count_moves_with_value(dq_a, max_index);
			max = dq_a->data[max_index];
			// ft_printf("max: %d\n", max);
			// ft_printf("max_index: %d\n", max_index);
		}
		else
		{
			max_index = get_max_index_index_with_limit(dq_a, amt - i, dq_b->data[(dq_b->front + 1) % dq_b->size]);
			move = count_moves_with_value(dq_a, max_index);
			max = dq_a->data[max_index];
			// ft_printf("dq_a->front: %d, dq_a->rear: %d\n",dq_a->front % dq_a->size, dq_a->rear % dq_a->size);
			// ft_printf("max: %d\n", max);
			// ft_printf("max_index: %d\n", max_index);
		}
		if (move == 1) // sa
		{
			sa(dq_a, dq_a->size);
			pb(dq_a, dq_b, dq_a->size);
		}
		else if (move == 2) // ra
		{
			while (dq_a->data[(dq_a->front + 1) % dq_a->size] != max)
			{
				ra(dq_a, dq_a->size);
				count++;
			}
			pb(dq_a, dq_b, dq_a->size);
			while (count > 0)
			{
				rra(dq_a, dq_a->size);
				count--;
			}
		}
		else if (move == 3) // rra
		{
			// ft_printf("FUCK");
			while (dq_a->data[(dq_a->front + 1) % dq_a->size] != max)
			{
				rra(dq_a, dq_a->size);
				count++;
			}
			pb(dq_a, dq_b, dq_a->size);
			while (count > 0)
			{
				ra(dq_a, dq_a->size);
				count--;
			}
		}
		else
			pb(dq_a, dq_b, dq_a->size);
		i++;
	}
}


void	make_desc_2_b(t_deque *dq_a, t_deque *dq_b, int amt)
{
	int	i;
	int	move;
	int	min_index;
	int	min;
	int	count;

	i = 0;
	count = 0;
	if (is_sorted_asc1(dq_a, amt))
		while (amt-- > 0)
			pb(dq_a, dq_b,dq_a->size);
	while (i < amt)
	{
		// ft_printf("i: %d\n", i);
		if (i == 0)
		{
			min_index = get_min_index(dq_a, amt - i);
			move = count_moves_with_value(dq_a, min_index);
			min = dq_a->data[min_index];

			// ft_printf("amt: %d\n", amt);
			// ft_printf("min: %d\n", min);
			// ft_printf("min_index: %d\n", min_index);
		}
		else
		{
			min_index = get_min_index_with_limit(dq_a, amt - i, dq_b->data[(dq_b->front + 1) % dq_b->size]);
			move = count_moves_with_value(dq_a, min_index);
			min = dq_a->data[min_index];
			// ft_printf("dq_b first element: %d\n", dq_b->data[(dq_b->front + 1) % dq_b->size]);
			// ft_printf("amt: %d\n", amt);
			// ft_printf("min: %d\n", min);
			// ft_printf("min_index: %d\n", min_index);
			// ft_printf("dq_a->front: %d\n",dq_a->front);
		}
		if (move == 1) // sa
		{
			sa(dq_a, dq_a->size);
			pb(dq_a, dq_b, dq_a->size);
		}
		else if (move == 2) // ra
		{
			while (dq_a->data[(dq_a->front + 1) % dq_a->size] != min)
			{
				ra(dq_a, dq_a->size);
				count++;
			}
			pb(dq_a, dq_b, dq_a->size);
			while (count > 0)
			{
				rra(dq_a, dq_a->size);
				count--;
			}
		}
		else if (move == 3) // rra
		{
			while (dq_a->data[(dq_a->front + 1) % dq_a->size] != min)
			{
				rra(dq_a, dq_a->size);
				count++;
			}
			pb(dq_a, dq_b, dq_a->size);
			while (count > 1)
			{
				ra(dq_a, dq_a->size);
				count--;
			}
		}
		else
			pb(dq_a, dq_b, dq_a->size);
		i++;
	}
}
