/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:52:31 by hyeonwch          #+#    #+#             */
/*   Updated: 2023/10/11 18:35:01 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;
	int		lst_len;

	temp = lst;
	lst_len = ft_lstsize(lst);
	while (lst_len-- > 0)
	{
		f(temp->content);
		temp = temp->next;
	}
}
