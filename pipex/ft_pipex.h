/* ************************************************************************** */
/*									  */
/*							:::	 ::::::::   */
/*   ft_pipex.h		   :+:   :+:	:+:   */
/*						  +:+ +:+	   +:+	*/
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>  +#+  +:+	   +#+	*/
/*						+#+#+#+#+#+   +#+	 */
/*   Created: 2024/03/08 17:41:00 by hyeonwch		#+#  #+#		  */
/*   Updated: 2024/03/09 22:57:10 by hyeonwch	   ###   ########.fr	*/
/*									  */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H
# include <sys/fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# define TRUE 1
# define FALSE 0
# define ERROR -1
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef int	t_boolean;
typedef struct s_pipex
{
	char	**cmd;
	int		infile;
	int		outfile;
	int		pipefd[2];
}	t_pipex;

t_boolean	check_access(char *str[]);
t_boolean	check_argc(int argc);
t_boolean	check_open(int *fd);
t_boolean	check_pipe(int *pipefd);
t_boolean	check_fork(pid_t *pid);
t_boolean	sanity_check(int argc, char *argv[], t_pipex *pipex);
char		*find_path(char *envp[]);
char		*find_command_path(char *command, char *envp[]);
void		execute_cmd(t_pipex *pipex, char **envp);
void		free_split(char **str);
#endif
