/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:41:02 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/01/15 20:16:10 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_spec(char c)
{
	if (c == '%')
		return (1);
	return (0);
}

static void	chk_spec(char **str, va_list *ap, ssize_t *total_len)
{
	if (!*(*str + 1))
	{
		(*total_len) = -1;
		return ;
	}
	if (*(*str + 1) == 'c')
		spec_c(va_arg(*ap, int), total_len);
	else if (*(*str + 1) == '%')
		spec_percent(total_len);
	else if (*(*str + 1) == 'd' || *(*str + 1) == 'i' || *(*str + 1) == 'u'
		|| *(*str + 1) == 'x' || *(*str + 1) == 'X')
		spec_int(*str, va_arg(*ap, int), total_len);
	else if (*(*str + 1) == 'p' || *(*str + 1) == 's')
		spec_ptr(*str, va_arg(*ap, void *), total_len);
	else
	{
		(*total_len) = -1;
		return ;
	}
	*str += 2;
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	char	*str_cp;
	ssize_t	total_len;

	total_len = 0;
	str_cp = (char *)str;
	va_start(ap, str);
	while (*str_cp)
	{
		if (is_spec(*str_cp))
		{
			chk_spec(&str_cp, &ap, &total_len);
			if (total_len == -1)
				break ;
			continue ;
		}
		if (write(1, str_cp++, 1) < 0)
		{
			total_len = -1;
			break ;
		}
		total_len++;
	}
	va_end(ap);
	return (total_len);
}
