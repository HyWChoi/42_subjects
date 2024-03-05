/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:23:36 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/03/05 15:19:02 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
				temp = ft_gnl_strdup(*saved_buff + i + 1);
			free(*saved_buff);
			*saved_buff = temp;
			return (*dst);
		}
		i++;
	}
	return (0);
}

static void	chk_read_buff(t_fd fd, char *r_buff, char **s_buff, char **dst)
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
				*s_buff = ft_gnl_strdup(r_buff + i + 1);
			return ;
		}
		if (fd.rd_size != BUFFER_SIZE)
			continue ;
		join_and_free(s_buff, &r_buff, dst, i + 1);
		*s_buff = *dst;
	}
	join_and_free(s_buff, &r_buff, dst, i);
}

int	get_next_line(int fd, char **line)
{
	static char	*saved_buff = 0;
	char		read_buff[BUFFER_SIZE + 1];
	t_fd		t_fd;

	t_fd.fd = fd;
	t_fd.rd_size = BUFFER_SIZE;
	if (t_fd.fd < 0 || read(t_fd.fd, NULL, 0) < 0)
	{
		if (saved_buff)
			free(saved_buff);
		saved_buff = 0;
		return (0);
	}
	if (saved_buff != 0 && chk_saved_buff(&saved_buff, line))
		return (0);
	chk_read_buff(t_fd, read_buff, &saved_buff, line);
	if (!(**line))
	{
		free(*line);
		*line = 0;
	}
	return (t_fd.fd < 0);
}
