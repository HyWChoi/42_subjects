/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:45:35 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/03/12 18:47:15 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_under6.h"

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
		free_split(split);
	}
	init_deque(dq_a, count_split + 1);
	init_deque(dq_b, count_split + 1);
}

static int	fill_dq_a(t_deque *dq_a, t_deque *dq_b, int argc, char *argv[])
{
	int		i;
	int		k;
	int		result;
	char	**split;

	i = 1;
	k = 0;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		while (split[k])
		{
			result = ft_atoi_push_swap(split[k++], dq_a, dq_b);
			if (!dq_a->data || !dq_b->data)
			{
				free_split(split);
				return (ERROR);
			}
			push_rear(dq_a, result, dq_a->size);
		}
		i++;
		k = 0;
		free_split(split);
	}
	return (0);
}

void	push_swap(t_deque *dq_a, t_deque *dq_b)
{
	size_t	i;
	int		depth;

	i = 0;
	depth = 0;
	if (is_sorted_asc(dq_a, dq_a->size))
		return ;
	if (count_dq(dq_a, dq_a->size) < 7)
	{
		is_argc_under_6(dq_a, dq_b);
		return ;
	}
	else
		sa(dq_a, dq_a->size);
	depth = calc_depth((dq_a)->size - 1);
	make_triangular(dq_a, dq_b);
	merge_triangle(dq_a, dq_b, depth);
	if (depth % 2 == 0)
		while (i++ < dq_a->size - 1)
			pa(dq_a, dq_b, dq_a->size);
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
	if (fill_dq_a(&dq_a, &dq_b, argc, argv) == ERROR)
		return (0);
	if (check_deq_dup_elem(&dq_a))
	{
		error_exit(&dq_a, &dq_b);
		return (0);
	}
	push_swap(&dq_a, &dq_b);
	free_deque_a_b(&dq_a, &dq_b);
	return (0);
}
