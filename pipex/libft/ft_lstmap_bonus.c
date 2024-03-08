/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:00:15 by hyeonwch          #+#    #+#             */
/*   Updated: 2023/10/12 17:55:26 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*map_lstnew(void *content, void (*del)(void *))
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (newnode == 0)
	{
		if (content)
			del(content);
		return (0);
	}
	newnode->content = content;
	newnode->next = 0;
	return (newnode);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list			*new_lst;
	t_list			*temp;

	if (!lst)
		return (0);
	new_lst = map_lstnew(f(lst->content), del);
	if (!new_lst || (new_lst && !(new_lst->content)))
	{
		ft_lstdelone(new_lst, del);
		return (0);
	}
	temp = new_lst;
	lst = lst->next;
	while (lst)
	{
		temp->next = map_lstnew(f(lst->content), del);
		if (!temp->next || (temp->next && !((temp->next)->content)))
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		temp = temp->next;
		lst = lst->next;
	}
	return (new_lst);
}
