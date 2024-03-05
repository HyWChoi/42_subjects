/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:49:02 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/03/04 19:13:26 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	spec_char(char *str, char c, ssize_t *total_len)
{
	if (*(str + 1) == 'c')
		spec_c(c, total_len);
	if (*(str + 1) == '%')
		spec_percent(total_len);
}

void	spec_c(char c, ssize_t *total_len)
{
	(*total_len)++;
	if (write(1, &c, 1) < 0)
		(*total_len) = -1;
}

void	spec_percent(ssize_t *total_len)
{
	(*total_len)++;
	if (write(1, "%", 1) < 0)
		(*total_len) = -1;
}
