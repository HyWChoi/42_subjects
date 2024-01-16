/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:07:48 by hyeonwch          #+#    #+#             */
/*   Updated: 2023/10/12 18:01:21 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			i;
	unsigned int	s_len;
	unsigned int	max_len;

	i = 0;
	s_len = ft_strlen(s);
	if (!(*s) || s_len < start || !len)
		return (ft_strdup(""));
	max_len = s_len - start;
	if (max_len <= len)
		len = max_len;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == 0)
		return (0);
	while (*(s + start + i) && i < len)
	{
		*(substr + i) = *(s + start + i);
		i++;
	}
	*(substr + i) = '\0';
	return (substr);
}
