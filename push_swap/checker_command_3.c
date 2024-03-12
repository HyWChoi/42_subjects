/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_command_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:48:29 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/03/12 15:21:21 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_command.h"

void	checker_rr(t_deque *dq_a, t_deque *dq_b, size_t size)
{
	checker_ra(dq_a, size);
	checker_rb(dq_b, size);
}

int	free_err(char *line)
{
	if (line)
		free(line);
	write(2, "Error\n", 6);
	return (ERROR);
}
