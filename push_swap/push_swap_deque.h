/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_deque.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 04:37:05 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/03/12 11:44:59 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_DEQUE_H
# define PUSH_SWAP_DEQUE_H
# include "./libft/libft.h"
# define TRUE 1
# define FALSE 0
# define ERROR -1
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef int	t_boolean;
typedef int	t_element;
typedef struct s_deque
{
	t_element	*data;
	size_t		size;
	int			front;
	int			rear;
}	t_deque;

void		init_deque(t_deque *dq, size_t size);
t_boolean	is_empty(t_deque *dq);
t_boolean	is_full(t_deque *dq, size_t size);
void		push_front(t_deque *dq, int num, size_t size);
void		push_rear(t_deque *dq, int num, size_t size);
t_element	pop_rear(t_deque *dq, size_t size);
t_element	pop_front(t_deque *dq, size_t size);
void		print_dq(t_deque *dq, size_t size);
int			count_dq(t_deque *dq, size_t size);
void		free_deque_a_b(t_deque *dq_a, t_deque *dq_b);

#endif
