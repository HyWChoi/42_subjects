/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:58:52 by hyeonwch          #+#    #+#             */
/*   Updated: 2023/10/11 21:46:12 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (n-- != 0)
		*((unsigned char *)(dst + i++)) = *((unsigned char *)src++);
	return (dst);
}
