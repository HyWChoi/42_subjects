/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:01:52 by hyeonwch          #+#    #+#             */
/*   Updated: 2023/10/11 14:30:28 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = 0;
	while (*(src + src_len))
		src_len++;
	dst_len = 0;
	while (*(dst + dst_len))
		dst_len++;
	i = 0;
	while (*(src + i) != '\0' && dst_len + i + 1 < dstsize)
	{
		*(dst + dst_len + i) = *(src + i);
		i++;
	}
	dst[dst_len + i] = '\0';
	if (dst_len >= dstsize)
		return (src_len + dstsize);
	return (dst_len + src_len);
}
