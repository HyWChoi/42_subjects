/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:52:34 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/03/27 06:06:10 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif
# if BUFFER_SIZE < 1
#  undef BUFFER_SIZE
#  define BUFFERSIZE 0
# endif
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <fcntl.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_fd
{
	int				fd;
	ssize_t			rd_size;
}	t_fd;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
size_t  ft_strslen(char **strs);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(char *str);
char	*ft_strdup(const char *s1);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	spec_char(char *str, char c, ssize_t *total_len);
void	spec_c(char c, ssize_t *total_len);
void	spec_percent(ssize_t *total_len);
void	spec_ptr(char *str, void *ptr, ssize_t *total_len);
void	spec_p(void *ptr, ssize_t *total_len);
void	spec_s(char *str, ssize_t *total_len);
void	spec_int(char *str, int n, ssize_t *total_len);
void	spec_d(int n, ssize_t *total_len);
void	spec_x_cap(int x, ssize_t *total_len);
void	spec_x(int x, ssize_t *total_len);
void	spec_u(unsigned int n, ssize_t *total_len);
void	chk_write(char *c, ssize_t *total_len);
void	chk_minus(long long *convert_n, ssize_t *total_len);
int		ft_printf(const char *str, ...);
char	*get_next_line(int fd);
size_t	ft_gnl_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_gnl_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_gnl_strjoin(char const *s1, char const *s2, size_t limit);
char	*ft_gnl_strdup(const char *s1);
void	join_and_free(char **saved_buff, char **read_buff, char **dst, int i);

#endif
