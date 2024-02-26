/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_calcs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 04:44:49 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/02/27 04:45:01 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CALCS_H
# define PUSH_SWAP_CALCS_H
# include "push_swap_element_status.h"

int	ft_pow(int base, int exp);
int	calc_depth(int i);
int	calc_dir(int depth, int i);
int	calc_amt(int depth, int i, int n);
#endif
