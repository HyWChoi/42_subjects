/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 22:32:10 by hyeonwch          #+#    #+#             */
/*   Updated: 2023/10/11 18:06:44 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char *sep, char c)
{
	if (*sep == c)
		return (0);
	return (1);
}

static int	count_words(char *str, char *sep, int total_size)
{
	int	flag;
	int	count;
	int	i;

	flag = 0;
	count = 0;
	i = 0;
	while (i < total_size)
	{
		if (is_sep(sep, *(str + i)) == 0 && flag == 1)
			flag = 0;
		if (is_sep(sep, *(str + i)) == 1 && flag == 0)
		{
			flag = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static int	count_alpha(char *str, char *sep)
{
	int	j;

	j = 0;
	while (is_sep(sep, *str) == 0 && *str != '\0')
		str++;
	while (is_sep(sep, *str) != 0 && *str != '\0')
	{
		str++;
		j++;
	}
	return (j);
}

static int	set_word(char *str, char *sep, char *dst)
{
	int	j;

	j = 0;
	while (is_sep(sep, *str) == 0 && *str != '\0')
	{
		str++;
		j++;
	}
	while (is_sep(sep, *str) != 0 && *str != '\0')
	{
		*dst++ = *str++;
		j++;
	}
	*dst = 0;
	return (j);
}

char	**ft_split(char const *s, char c)
{
	int		num_str;
	char	**result;
	int		num_alpha;
	int		i;

	num_str = count_words((char *)s, &c, ft_strlen(s));
	result = (char **)malloc(sizeof(char *) * (num_str + 1));
	if (result == 0)
		return (0);
	i = 0;
	while (i < num_str && *s)
	{
		num_alpha = count_alpha((char *)s, &c);
		*(result + i) = (char *)malloc(sizeof(char) * (num_alpha + 1));
		if (!*(result + i))
		{
			while (i--)
				free(result[i]);
			free(result);
			return (NULL);
		}
		s += set_word((char *)s, &c, *(result + i++));
	}
	*(result + i) = 0;
	return (result);
}
