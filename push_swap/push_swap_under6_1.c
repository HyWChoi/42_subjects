/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_under6_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:48:24 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/03/06 18:48:25 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_under6.h"

void	sort_first(t_deque *dq_a)
{
	if (is_first_bigger_second(dq_a, dq_a->size))
	{
		if (is_first_bigger_last(dq_a, dq_a->size))
		{
			if (is_second_bigger_last(dq_a, dq_a->size))
			{
				sa(dq_a, dq_a->size);
				rra(dq_a, dq_a->size);
				ft_printf("rra\n");
			}
			else
				ra(dq_a, dq_a->size);
		}
		else
			sa(dq_a, dq_a->size);
	}
}

void	sort_second(t_deque *dq_a)
{
	if (!is_first_bigger_last(dq_a, dq_a->size))
	{
		sa(dq_a, dq_a->size);
		ra(dq_a, dq_a->size);
	}
	else
	{
		ft_printf("rra\n");
		rra(dq_a, dq_a->size);
	}
}

void	sort_rev_first(t_deque *dq_b)
{
	if (!is_first_bigger_second(dq_b, dq_b->size))
	{
		if (!is_first_bigger_last(dq_b, dq_b->size))
		{
			if (!is_second_bigger_last(dq_b, dq_b->size))
			{
				sb(dq_b, dq_b->size);
				rb(dq_b, dq_b->size);
				ft_printf("rrb\n");
			}
			else
				rb(dq_b, dq_b->size);
		}
		else
			sb(dq_b, dq_b->size);
	}
}

void	sort_rev_second(t_deque *dq_b)
{
	if (is_first_bigger_last(dq_b, dq_b->size))
	{
		sb(dq_b, dq_b->size);
		rb(dq_b, dq_b->size);
	}
	else
	{
		ft_printf("rrb\n");
		rrb(dq_b, dq_b->size);
	}
}

void	decide_move_under_6(size_t *count_a, size_t *count_b,
						t_deque *dq_a, t_deque *dq_b)
{
	if (*count_a > 0 && *count_b > 0)
	{
		if (is_rear_bigger_opposite_front(dq_a, dq_b))
		{
			rra(dq_a, dq_a->size);
			ft_printf("rra\n");
			(*count_a)--;
		}
		else
		{
			pa(dq_a, dq_b, dq_a->size);
			(*count_b)--;
		}
	}
	else if (*count_a == 0 && *count_b > 0)
	{
		pa(dq_a, dq_b, dq_a->size);
		(*count_b)--;
	}
	else
	{
		rra(dq_a, dq_a->size);
		ft_printf("rra\n");
		(*count_a)--;
	}
}




