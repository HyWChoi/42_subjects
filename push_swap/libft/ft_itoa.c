/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:55:21 by hyeonwch          #+#    #+#             */
/*   Updated: 2023/10/09 22:13:25 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_numdigits(long long n)
{
	int	count;

	count = 0;
	if (n < 0)
		n *= -1;
	while (n / 10 > 0)
	{
		count++;
		n /= 10;
	}
	return (count + 1);
}

static void	insert_nbr(long long n, char *result, int num_digits)
{
	if (n < 0)
	{
		n *= -1;
		*result = '-';
		result++;
		num_digits--;
	}
	if (n / 10 > 0)
	{
		*(result + num_digits) = n % 10 + '0';
		insert_nbr(n / 10, result, num_digits - 1);
	}
	else
		*result = n + '0';
}

char	*ft_itoa(int n)
{
	size_t	num_digits;
	char	*result;

	num_digits = count_numdigits(n);
	if (n < 0)
		num_digits++;
	result = (char *)malloc(sizeof(char) * (num_digits + 1));
	if (result == 0)
		return (0);
	insert_nbr(n, result, num_digits - 1);
	*(result + num_digits) = '\0';
	return (result);
}
