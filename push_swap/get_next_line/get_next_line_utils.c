/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:26:25 by hyeonwch          #+#    #+#             */
/*   Updated: 2023/11/02 16:30:46 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = 0;
	if (src == 0)
	{
		*dst = '\0';
		return (src_len);
	}
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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = 0;
	if (src == 0)
	{
		*dst = '\0';
		return (src_len);
	}
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

char	*ft_strjoin(char const *s1, char const *s2, size_t limit)
{
	int		s1_len;
	char	*result;

	s1_len = 0;
	while (s1 && *(s1 + s1_len))
		s1_len++;
	result = (char *)malloc(sizeof(char) * (s1_len + limit + 1));
	if (result == 0)
		return (0);
	ft_strlcpy(result, s1, s1_len + limit + 1);
	ft_strlcat(result, s2, s1_len + limit + 1);
	return (result);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*copy;

	len = 0;
	i = 0;
	while (*(s1 + len))
		len++;
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (copy == 0)
		return (0);
	while (len - i >= 0)
	{
		*(copy + i) = *(s1 + i);
		i++;
	}
	return (copy);
}

void	join_and_free(char **saved_buff, char **read_buff, char **dst, int i)
{
	*dst = ft_strjoin(*saved_buff, *read_buff, i);
	if (*saved_buff)
		free(*saved_buff);
	*saved_buff = 0;
}
