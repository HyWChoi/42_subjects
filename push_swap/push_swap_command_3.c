/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:48:31 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/02/20 17:48:32 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_command.h"

void	rrr(t_deque *dq_a, t_deque *dq_b, size_t size)
{
	rra(dq_a, size);
	rrb(dq_b, size);
	ft_printf("rrr\n");
}
