/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:45:29 by hyeonwch          #+#    #+#             */
/*   Updated: 2023/10/12 17:59:45 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char const *set, char c)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

static int	count_total_len(char const *s1, char const *set)
{
	size_t	s1_len;

	while (is_set(set, *s1))
		s1++;
	if (!(*s1))
		return (0);
	s1_len = ft_strlen(s1) - 1;
	while (is_set(set, *(s1 + s1_len)))
		s1_len--;
	return (s1_len + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	total_len;
	char	*result;
	int		i;

	i = 0;
	if (!s1)
		return (ft_strdup(""));
	total_len = count_total_len(s1, set);
	result = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!result)
		return (0);
	while (is_set(set, *s1))
		s1++;
	while (total_len-- > 0)
	{
		*(result + i) = *(s1 + i);
		i++;
	}
	*(result + i) = '\0';
	return (result);
}
