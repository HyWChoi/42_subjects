/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:23:36 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/03/04 20:50:48 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_list	*find_fd(int fd, t_list **lst_head)
{
	t_list	*lst;
	t_list	*prev;

	lst = *lst_head;
	prev = 0;
	while (lst)
	{
		if (lst->fd == fd)
			return (lst);
		prev = lst;
		lst = lst->next;
	}
	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (0);
	lst->fd = fd;
	lst->saved_buff = 0;
	lst->next = 0;
	lst->rd_size = BUFFER_SIZE;
	if (prev)
		prev->next = lst;
	else
		*lst_head = lst;
	return (lst);
}

static void	ft_lstdelone(t_list **lst_head, t_list *to_delete)
{
	t_list	*temp;
	t_list	*prev;

	if (!lst_head || !to_delete)
		return ;
	temp = *lst_head;
	prev = 0;
	while (temp)
	{
		if (temp == to_delete)
		{
			if (prev)
				prev->next = temp->next;
			else
				*lst_head = temp->next;
			if (temp->saved_buff)
				free(temp->saved_buff);
			free(temp);
			return ;
		}
		prev = temp;
		temp = temp->next;
	}
}

static char	*chk_saved_buff(char **saved_buff, char **dst)
{
	size_t	i;
	char	*temp;
	size_t	saved_buff_len;

	i = 0;
	temp = 0;
	saved_buff_len = 0;
	while (*saved_buff && *(*saved_buff + saved_buff_len))
		saved_buff_len++;
	while (i < saved_buff_len)
	{
		if (*(*saved_buff + i) == '\n')
		{
			*dst = ft_gnl_strjoin(0, *saved_buff, i + 1);
			if (i < BUFFER_SIZE && *(*saved_buff + i + 1))
				temp = ft_strdup(*saved_buff + i + 1);
			free(*saved_buff);
			*saved_buff = temp;
			return (*dst);
		}
		i++;
	}
	return (0);
}

static void	chk_read_buff(t_list fd, char *r_buff, char **s_buff, char **dst)
{
	ssize_t	i;

	while (fd.rd_size == BUFFER_SIZE)
	{
		i = 0;
		fd.rd_size = read(fd.fd, r_buff, BUFFER_SIZE);
		if (fd.rd_size < 0)
			return ;
		*(r_buff + fd.rd_size) = '\0';
		while (i < fd.rd_size && *(r_buff + i) && (*(r_buff + i) != '\n'))
			i++;
		if (*(r_buff + i) == '\n')
		{
			join_and_free(s_buff, &r_buff, dst, i + 1);
			if (i + 1 < fd.rd_size && *(r_buff + i + 1))
				*s_buff = ft_strdup(r_buff + i + 1);
			return ;
		}
		if (fd.rd_size != BUFFER_SIZE)
			continue ;
		join_and_free(s_buff, &r_buff, dst, i + 1);
		*s_buff = *dst;
	}
	join_and_free(s_buff, &r_buff, dst, i);
}

char	*get_next_line(int fd)
{
	static t_list	*lst_head = 0;
	t_list			*lst;
	char			read_buff[BUFFER_SIZE + 1];
	char			*dst;

	lst = find_fd(fd, &lst_head);
	dst = 0;
	*read_buff = 0;
	if (lst->fd < 0 || read(lst->fd, NULL, 0) < 0)
	{
		ft_lstdelone(&lst_head, lst);
		return (0);
	}
	if (lst->saved_buff != 0 && chk_saved_buff(&(lst->saved_buff), &dst))
		return (dst);
	chk_read_buff(*lst, read_buff, &(lst->saved_buff), &dst);
	if (!*dst)
	{
		ft_lstdelone(&lst_head, lst);
		free(dst);
		dst = 0;
	}
	return (dst);
}
