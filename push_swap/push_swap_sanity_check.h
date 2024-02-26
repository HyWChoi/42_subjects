/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sanity_check.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 04:28:11 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/02/27 04:28:12 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_SANITY_CHECK_H
# define PUSH_SWAP_SANITY_CHECK_H
# include "watch_deque.h"

int		ft_atoi_push_swap(char *str, t_deque *dq_a, t_deque *dq_b);
int		ft_is_number(char *str);
void	error_exit(t_deque *dq_a, t_deque *dq_b);

#endif
