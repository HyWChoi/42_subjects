/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:10:23 by hyeonwch          #+#    #+#             */
/*   Updated: 2023/10/11 14:29:29 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = 0;
	while (*(src + src_len))
		src_len++;
	if (dstsize == 0)
		return (src_len);
	while (*src && dstsize - 1 != 0)
	{
		*dst++ = *src++;
		dstsize--;
	}
	*dst = '\0';
	return (src_len);
}
