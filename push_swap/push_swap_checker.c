/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:47:30 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/03/04 18:53:00 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_merge.h"

t_boolean	checker(t_deque *dq_a, t_deque *dq_b)
{
	if (is_sorted_asc(dq_a, dq_a->size) && is_empty(dq_b))
		return (TRUE);
	else
		return (FALSE);
}
