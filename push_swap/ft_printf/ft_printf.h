/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:40:41 by hyeonwch          #+#    #+#             */
/*   Updated: 2023/11/18 16:31:13 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

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

#endif
