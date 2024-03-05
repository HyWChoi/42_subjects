/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:08:01 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/03/04 19:15:46 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	spec_ptr(char *str, void *ptr, ssize_t *total_len)
{
	if (*(str + 1) == 's')
		spec_s((char *)ptr, total_len);
	else if (*(str + 1) == 'p')
	{
		if (!ptr)
		{
			(*total_len) += 3;
			if (write(1, "0x0", 3) < 0)
				(*total_len) = -1;
			return ;
		}
		spec_p(ptr, total_len);
	}
}

void	spec_s(char *str, ssize_t *total_len)
{
	size_t	str_len;

	str_len = 0;
	if (!str)
	{
		(*total_len) += 6;
		if (write(1, "(null)", 6) < 0)
			(*total_len) = -1;
		return ;
	}
	while (*(str + str_len))
		str_len++;
	(*total_len) += str_len;
	if (write(1, str, str_len) < 0)
		(*total_len) = -1;
}

void	spec_p(void *ptr, ssize_t *total_len)
{
	unsigned long long	divided_n;
	char				*x_lst;
	char				c;
	unsigned long long	remained_n;

	x_lst = "0123456789abcdef";
	divided_n = (unsigned long long)ptr;
	remained_n = divided_n / 16;
	if (divided_n > 0)
	{
		c = x_lst[divided_n % 16];
		(*total_len)++;
		spec_p((void *)remained_n, total_len);
		if ((*total_len) != -1 && write(1, &c, 1) < 0)
			(*total_len) = -1;
	}
	else
	{
		(*total_len) += 2;
		if (write(1, "0x", 2) < 0)
			(*total_len) = -1;
	}
}
