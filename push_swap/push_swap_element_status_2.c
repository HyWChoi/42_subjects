/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_element_status_2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:55:55 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/02/20 17:56:20 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_element_status.h"

boolean	is_rear_bigger_opposite_rear(t_deque *dq, t_deque *opposite)
{
	if (dq->data[dq->rear % dq->size]
		< opposite->data[opposite->rear % opposite->size])
		return (FALSE);
	return (TRUE);
}

boolean	is_rear_bigger_opposite_front(t_deque *dq, t_deque *opposite)
{
	if (dq->data[dq->rear % dq->size]
		< opposite->data[(opposite->front + 1) % opposite->size])
		return (FALSE);
	return (TRUE);
}
