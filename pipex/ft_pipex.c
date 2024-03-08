/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_pipex.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>	 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/03/08 17:39:55 by hyeonwch		  #+#	#+#			 */
/*   Updated: 2024/03/08 18:19:52 by hyeonwch		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft_pipex.h"

t_boolean	check_access(const char *str[])
{
	const char	*file1;
	const char	*file2;
	int		mod;

	mod = R_OK | W_OK;
	file1 = str[1];
	file2 = str[2];
	if (access( file1, mod ) == ERROR)
	{
		perror("file1 is not exist or permission denied.");
		return (FALSE);
	}
	if (access( file2, mod ) == ERROR)
	{
		perror("file2 is not exist or permission denied.");
		return (FALSE);
	}
	return (TRUE);
}

t_boolean	check_argc(int argc)
{
	if (argc != 5)
	{
		perror("Usage: ./pipex file1 cmd1 cmd2 file2");
		return (FALSE);
	}
	return (TRUE);
}

t_boolean	check_error(int fd)
{
	if (fd == ERROR)
	{
		perror("open");
		return (FALSE);
	}
	return (TRUE);
}
t_boolean	check_pipe_error(int *pipefd)
{
	pipe(pipefd);
	if (*pipefd == ERROR || *(pipefd + 1) == ERROR)
	{
		perror("pipe");
		return (FALSE);
	}
	return (TRUE);
}

t_boolean	check_fork_error(pid_t *pid)
{
	*pid = fork();
	if (*pid == ERROR)
	{
		perror("fork");
		return (FALSE);
	}
	return (TRUE);
}

int	main(int argc, const char *argv[])
{
	int	pipefd[2];
	int	infile;
	int	outfile;
	pid_t	pid1;
	pid_t	pid2;

	check_argc(argc);
	check_access(argv);
	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (!check_error(infile) || !check_error(outfile))
		return (0);
	if (!check_pipe_error(pipefd))
		return (0);
	if (!check_fork_error(&pid1))
		return (0);
	if (pid1 == 0)
	{
	}
	if (!check_fork_error(&pid2))
		return (0);
	if (pid2 == 0)
	{
		dup2(infile, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		execute_command(argv[2], envp);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	close(infile);
	close(outfile);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return 0;
}
