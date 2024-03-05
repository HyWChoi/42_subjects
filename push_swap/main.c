/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 04:45:04 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/03/05 21:10:35 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_merge.h"

static void	init_dq_a_b(t_deque *dq_a, t_deque *dq_b, int argc, char *argv[])
{
	int		i;
	int		k;
	size_t	count_split;
	char	**split;

	i = 1;
	k = 0;
	count_split = 0;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		while (split[k++])
			count_split++;
		i++;
		k = 0;
		while (split[k])
			free(split[k++]);
		free(split);
		k = 0;
	}
	init_deque(dq_a, count_split + 1);
	init_deque(dq_b, count_split + 1);
}

static void	fill_dq_a(t_deque *dq_a, t_deque *dq_b, int argc, char *argv[])
{
	int		i;
	int		k;
	char	**split;

	i = 1;
	k = 0;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		while (split[k])
			push_rear(dq_a, ft_atoi_push_swap(split[k++], dq_a, dq_b),
				dq_a->size);
		i++;
		k = 0;
		while (split[k])
			free(split[k++]);
		free(split);
		k = 0;
	}
}

void	size_2(t_deque *dq_a)
{
	if (is_first_bigger_second(dq_a, dq_a->size))
		sa(dq_a, dq_a->size);
}

void	size_3(t_deque *dq_a)
{
	if (is_first_bigger_second(dq_a, dq_a->size))
	{
		if (is_first_bigger_last(dq_a, dq_a->size))
		{
			if (is_second_bigger_last(dq_a, dq_a->size))
			{
				sa(dq_a, dq_a->size);
				rra(dq_a, dq_a->size);
			}
			else
				ra(dq_a, dq_a->size);
		}
		else
			sa(dq_a, dq_a->size);
	}
	else
	{
		if (is_first_bigger_last(dq_a, dq_a->size))
		{
			sa(dq_a, dq_a->size);
			ra(dq_a, dq_a->size);
		}
		else
			rra(dq_a, dq_a->size);
	}
}

void	is_argc_under_3(t_deque *dq_a)
{
	if (dq_a->size == 2)
		size_2(dq_a);
	else if (dq_a->size == 3)
		size_3(dq_a);
}

void	push_swap(t_deque *dq_a, t_deque *dq_b)
{
	size_t	i;
	int		depth;

	i = 0;
	depth = 0;
	if (count_dq(dq_a, dq_a->size) < 3)
		is_argc_under_3(dq_a);
	if (is_sorted_asc(dq_a, dq_a->size))
		return ;
	else
		sa(dq_a, dq_a->size);
	depth = calc_depth((dq_a)->size - 1);
	make_triangular(dq_a, dq_b);
	merge_triangle(dq_a, dq_b, depth);
	if (depth % 2 == 0)
		while (i++ < dq_a->size - 1)
			pa(dq_a, dq_b, dq_a->size);
	free(dq_a->data);
	free(dq_b->data);
}

int	main(int argc, char *argv[])
{
	t_deque	dq_a;
	t_deque	dq_b;

	if (argc < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	init_dq_a_b(&dq_a, &dq_b, argc, argv);
	fill_dq_a(&dq_a, &dq_b, argc, argv);
	push_swap(&dq_a, &dq_b);
	return (0);
}
