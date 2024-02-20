/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sanity_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:56:46 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/02/20 17:56:47 by hyeonwch         ###   ########.fr       */
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
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	result *= sign;
	if (result > INT_MAX || result < INT_MIN)
		error_exit(dq_a, dq_b);
	return (result);
}

int	ft_is_number(char *str)
{
	if (*str == '\0')
		return (ERROR);
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (ERROR);
	while (*str)
	{
		if (!ft_isdigit(*str++))
			return (ERROR);
	}
	return (TRUE);
}

void	error_exit(t_deque *dq_a, t_deque *dq_b)
{
	free(dq_a->data);
	free(dq_b->data);
	exit(1);
}
