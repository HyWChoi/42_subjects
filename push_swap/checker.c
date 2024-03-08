/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:20:40 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/03/08 12:31:20 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "checker_command.h"
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

static void	command_cmp(t_deque *dq_a, t_deque *dq_b, char *line)
{
	if (ft_strncmp(line, "sa", 2) == 0)
		checker_sa(dq_a, dq_a->size);
	else if (ft_strncmp(line, "sb", 2) == 0)
		checker_sb(dq_b, dq_b->size);
	else if (ft_strncmp(line, "pa", 2) == 0)
		checker_pa(dq_a, dq_b, dq_a->size);
	else if (ft_strncmp(line, "pb", 2) == 0)
		checker_pb(dq_a, dq_b, dq_b->size);
	else if (ft_strncmp(line, "ra", 2) == 0)
		checker_ra(dq_a, dq_a->size);
	else if (ft_strncmp(line, "rb", 2) == 0)
		checker_rb(dq_b, dq_b->size);
	else if (ft_strncmp(line, "rra", 3) == 0)
		checker_rra(dq_a, dq_a->size);
	else if (ft_strncmp(line, "rrb", 3) == 0)
		checker_rrb(dq_b, dq_b->size);
	else if (ft_strncmp(line, "rrr", 3) == 0)
		checker_rrr(dq_a, dq_b, dq_a->size);
}

static void	checker(t_deque *dq_a, t_deque *dq_b)
{
	char	*line;
	int		ret;

	line = 0;
	while (1)
	{
		ret = get_next_line(0, &line);
		if (ret == -1)
			return ;
		if (!line)
			break ;
		command_cmp(dq_a, dq_b, line);
		free(line);
		line = 0;
	}
	if (is_sorted_asc(dq_a, dq_a->size))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char *argv[])
{
	t_deque	dq_a;
	t_deque	dq_b;
	char	*dummy_line;

	if (argc < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	init_dq_a_b(&dq_a, &dq_b, argc, argv);
	fill_dq_a(&dq_a, &dq_b, argc, argv);
	if (check_deq_dup_elem(&dq_a))
	{
		error_exit(&dq_a, &dq_b);
		return (0);
	}
	checker(&dq_a, &dq_b);
	free(dq_a.data);
	free(dq_b.data);
	get_next_line(-1, &dummy_line);
	return (0);
}
