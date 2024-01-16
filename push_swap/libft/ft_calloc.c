/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:53:00 by hyeonwch          #+#    #+#             */
/*   Updated: 2023/10/11 15:48:32 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc;

	if (!size || !count)
	{
		alloc = (void *)malloc(0);
		if (alloc == 0)
			return (0);
		*(unsigned char *)alloc = 0;
		return (alloc);
	}
	alloc = (void *)malloc(size * count);
	if (alloc == 0)
		return (0);
	ft_bzero(alloc, size * count);
	return (alloc);
}
