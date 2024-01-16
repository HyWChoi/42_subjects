/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:52:13 by hyeonwch          #+#    #+#             */
/*   Updated: 2023/10/09 22:29:04 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
