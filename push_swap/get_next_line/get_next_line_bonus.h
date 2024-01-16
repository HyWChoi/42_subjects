/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 03:04:33 by hyeonwch          #+#    #+#             */
/*   Updated: 2023/11/02 17:10:31 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# if BUFFER_SIZE < 1
#  undef BUFFER_SIZE
#  define BUFFERSIZE 0
# endif
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				fd;
	char			*saved_buff;
	struct s_list	*next;
	ssize_t			rd_size;
}	t_list;

char	*get_next_line(int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2, size_t limit);
char	*ft_strdup(const char *s1);
void	join_and_free(char **saved_buff, char **read_buff, char **dst, int i);

#endif
