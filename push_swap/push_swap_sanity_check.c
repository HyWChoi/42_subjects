/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sanity_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:56:46 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/03/12 11:50:59 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_sanity_check.h"

int	ft_atoi_push_swap(char *str, t_deque *dq_a, t_deque *dq_b)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		ft_is_number(str + 1, dq_a, dq_b);
		if (*str == '-')
			sign *= -1;
		str++;
	}
	else if (*str < '0' || *str > '9')
		error_exit(dq_a, dq_b);
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
		if (*str != '\0' && (*str < '0' || *str > '9'))
			error_exit(dq_a, dq_b);
	}
	result *= sign;
	if (result > INT_MAX || result < INT_MIN)
		error_exit(dq_a, dq_b);
	return (result);
}

void	ft_is_number(char *str, t_deque *dq_a, t_deque *dq_b)
{
	if (*str < '0' || *str > '9')
		error_exit(dq_a, dq_b);
}

void	error_exit(t_deque *dq_a, t_deque *dq_b)
{
	ft_printf("Error\n");
	free(dq_a->data);
	free(dq_b->data);
	dq_a->data = NULL;
	dq_b->data = NULL;
	return ;
}

t_boolean	check_deq_dup_elem(t_deque *dq)
{
	size_t	i;
	size_t	k;

	i = (dq->front + 1) % dq->size;
	k = 0;
	while ((i != dq->rear % dq->size) && (k++ < dq->size - 1))
	{
		if (dq->data[i % dq->size] == dq->data[(i + 1) % dq->size])
			return (TRUE);
		i = (i + 1) % dq->size;
	}
	return (FALSE);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}
