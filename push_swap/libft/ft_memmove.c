/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 21:51:04 by hyeonwch          #+#    #+#             */
/*   Updated: 2023/10/11 21:47:37 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	i = 0;
	if (!dst && !src)
		return (0);
	if (src < dst)
	{
		while (len != 0)
		{
			*((unsigned char *)(dst + len - 1))
				= *((unsigned char *)src + len - 1);
			len--;
		}
	}
	else if (src == dst)
		return (dst);
	else
	{
		while (len != 0)
		{
			*((unsigned char *)(dst + i++)) = *((unsigned char *)src++);
			len--;
		}
	}
	return (dst);
}
