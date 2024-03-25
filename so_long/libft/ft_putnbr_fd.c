/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:43:44 by hyeonwch          #+#    #+#             */
/*   Updated: 2023/10/11 21:47:55 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	convert_n;
	char		c;

	convert_n = n;
	if (convert_n < 0)
	{
		convert_n *= -1;
		write(fd, "-", 1);
	}
	if (convert_n / 10 > 0)
	{
		c = convert_n % 10 + '0';
		ft_putnbr_fd(convert_n / 10, fd);
		write(fd, &c, 1);
	}
	else
	{
		c = convert_n + '0';
		write(fd, &c, 1);
	}
}
