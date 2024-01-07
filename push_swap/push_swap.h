/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:23:59 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/01/04 18:03:02 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# define TRUE 1
# define FALSE 0
# define ERROR -1
# define MAX_DEQUE_SIZE 5

typedef int boolean;
typedef int element;
typedef struct s_deque
{
	element *data;
	int front;
	int rear;
} t_deque;

#endif
