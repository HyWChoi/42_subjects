/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 03:04:33 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/03/12 13:35:37 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif
# if BUFFER_SIZE < 1
#  undef BUFFER_SIZE
#  define BUFFERSIZE 0
# endif
# include <unistd.h>
# include <stdlib.h>

typedef struct s_fd
{
	int				fd;
	ssize_t			rd_size;
}	t_fd;

int		get_next_line(int fd, char **line);
size_t	ft_gnl_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_gnl_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_gnl_strjoin(char const *s1, char const *s2, size_t limit);
char	*ft_gnl_strdup(const char *s1);
void	join_and_free(char **saved_buff, char **read_buff, char **dst, int i);

#endif
