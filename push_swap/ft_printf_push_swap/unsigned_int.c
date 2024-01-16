/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:06:17 by hyeonwch          #+#    #+#             */
/*   Updated: 2023/11/13 20:31:15 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	spec_u(unsigned int n, ssize_t *total_len)
{
	char	c;

	if (n / 10 > 0)
	{
		c = n % 10 + '0';
		(*total_len)++;
		spec_u(n / 10, total_len);
		if ((*total_len) != -1 && write(1, &c, 1) < 0)
			(*total_len) = -1;
	}
	else
	{
		c = n + '0';
		(*total_len)++;
		if ((*total_len) != -1 && write(1, &c, 1) < 0)
			(*total_len) = -1;
	}
}

void	spec_x_cap(int x, ssize_t *total_len)
{
	unsigned int	divided_n;
	char			*x_lst;
	char			c;

	x_lst = "0123456789ABCDEF";
	divided_n = x;
	if (divided_n / 16 > 0)
	{
		c = x_lst[divided_n % 16];
		(*total_len)++;
		spec_x_cap(divided_n / 16, total_len);
		chk_write(&c, total_len);
	}
	else
	{
		c = x_lst[divided_n % 16];
		(*total_len)++;
		chk_write(&c, total_len);
	}
}

void	spec_x(int x, ssize_t *total_len)
{
	unsigned int	divided_n;
	char			*x_lst;
	char			c;

	x_lst = "0123456789abcdef";
	divided_n = x;
	if (divided_n / 16 > 0)
	{
		c = x_lst[divided_n % 16];
		(*total_len)++;
		spec_x(divided_n / 16, total_len);
		chk_write(&c, total_len);
	}
	else
	{
		c = x_lst[divided_n % 16];
		(*total_len)++;
		chk_write(&c, total_len);
	}
}
