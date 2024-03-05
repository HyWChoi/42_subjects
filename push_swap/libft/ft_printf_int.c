/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:48:38 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/03/04 19:13:20 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	spec_int(char *str, int n, ssize_t *total_len)
{
	if (*(str + 1) == 'd' || *(str + 1) == 'i')
		spec_d(n, total_len);
	if (*(str + 1) == 'x')
		spec_x(n, total_len);
	if (*(str + 1) == 'X')
		spec_x_cap(n, total_len);
	if (*(str + 1) == 'u')
		spec_u((unsigned int)n, total_len);
}

void	chk_write(char *c, ssize_t *total_len)
{
	if ((*total_len) != -1 && write(1, c, 1) < 0)
		(*total_len) = -1;
}

void	chk_minus(long long *convert_n, ssize_t *total_len)
{
	*convert_n *= -1;
	(*total_len)++;
	chk_write("-", total_len);
}

void	spec_d(int n, ssize_t *total_len)
{
	long long	convert_n;
	char		c;

	convert_n = n;
	if (convert_n < 0)
	{
		chk_minus(&convert_n, total_len);
		if ((*total_len) == -1)
			return ;
	}
	if (convert_n / 10 > 0)
	{
		c = convert_n % 10 + '0';
		(*total_len)++;
		spec_d(convert_n / 10, total_len);
		chk_write(&c, total_len);
	}
	else
	{
		c = convert_n + '0';
		(*total_len)++;
		chk_write(&c, total_len);
	}
}
