/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watch_deque.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:50:22 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/01/12 23:50:40 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "watch_deque.h"

void	watch_dq_a_state(t_deque *a, size_t size)
{
	ft_printf("dq_a's state: ");
	print_dq(a, size);
}

void	watch_dq_b_state(t_deque *b, size_t size)
{
	ft_printf("dq_b's state: ");
	print_dq(b, size);
}

void	watch_dq_a_b_state(t_deque *a, t_deque *b, size_t size)
{
	watch_dq_a_state(a, size);
	watch_dq_b_state(b, size);
}
