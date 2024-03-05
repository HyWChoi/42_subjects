/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   push_swap_devide_2.c							   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>	 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/02/20 17:30:36 by hyeonwch		  #+#	#+#			 */
/*   Updated: 2024/02/20 17:31:17 by hyeonwch		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap_devide.h"

int	count_moves_with_value(t_deque *dq, int value_index)
{
	int	ra;
	int	rra;
	int	sa;
	int	pb;

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

void	rotate_and_push(t_deque *dq_a, t_deque *dq_b, int move, int target)
{
	int	count;

	count = dq_a->data[(dq_a->front + 1) % dq_a->size];
	while (dq_a->data[(dq_a->front + 1) % dq_a->size] != target)
	{
		if (move == 2)
			ra(dq_a, dq_a->size);
		else
		{
			rra(dq_a, dq_a->size);
			ft_printf("rra\n");
		}
	}
	pb(dq_a, dq_b, dq_a->size);
	while (dq_a->data[(dq_a->front + 1) % dq_a->size] != count)
	{
		if (move == 2)
		{
			rra(dq_a, dq_a->size);
			ft_printf("rra\n");
		}
		else
			ra(dq_a, dq_a->size);
	}
}

void	move_t_elements(t_deque *dq_a, t_deque *dq_b, int move, int target)
{
	if (move == 1)
	{
		sa(dq_a, dq_a->size);
		pb(dq_a, dq_b, dq_a->size);
	}
	else if (move == 2 || move == 3)
		rotate_and_push(dq_a, dq_b, move, target);
	else
		pb(dq_a, dq_b, dq_a->size);
}

void	make_asc_2_b(t_deque *dq_a, t_deque *dq_b, int amt)
{
	int	i;
	int	max_index;
	int	move;

	i = 0;
	if (is_sorted_desc(dq_a, amt))
		while (amt-- > 0)
			pb(dq_a, dq_b, dq_a->size);
	while (i < amt)
	{
		if (i == 0)
		{
			max_index = get_max_index(dq_a, amt - i);
			move = count_moves_with_value(dq_a, max_index);
		}
		else
		{
			max_index = get_max_index_index_with_limit(dq_a, amt - i,
					dq_b->data[(dq_b->front + 1) % dq_b->size]);
			move = count_moves_with_value(dq_a, max_index);
		}
		move_t_elements(dq_a, dq_b, move, dq_a->data[max_index]);
		i++;
	}
}

void	make_desc_2_b(t_deque *dq_a, t_deque *dq_b, int amt)
{
	int	i;
	int	min_index;
	int	move;

	i = 0;
	if (is_sorted_asc(dq_a, amt))
		while (amt-- > 0)
			pb(dq_a, dq_b, dq_a->size);
	while (i < amt)
	{
		if (i == 0)
		{
			min_index = get_min_index(dq_a, amt - i);
			move = count_moves_with_value(dq_a, min_index);
		}
		else
		{
			min_index = get_min_index_with_limit(dq_a, amt - i,
					dq_b->data[(dq_b->front + 1) % dq_b->size]);
			move = count_moves_with_value(dq_a, min_index);
		}
		move_t_elements(dq_a, dq_b, move, dq_a->data[min_index]);
		i++;
	}
}
