/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:08:49 by hyeonwch          #+#    #+#             */
/*   Updated: 2023/10/11 14:47:49 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		s_len;
	int		i;
	char	*result;

	i = 0;
	s_len = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (s_len + 1));
	if (result == 0)
		return (0);
	while (i < s_len)
	{
		*(result + i) = f(i, *(s + i));
		i++;
	}
	*(result + i) = '\0';
	return (result);
}
