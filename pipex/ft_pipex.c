/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:53:35 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/03/12 19:06:28 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	change_fd_children(t_pipex *pipex, char *argv[], char **envp)
{
	pipex->cmd = ft_split(argv[2], ' ');
	close(pipex->pipefd[0]);
	dup2(pipex->infile, STDIN_FILENO);
	dup2(pipex->pipefd[1], STDOUT_FILENO);
	close(pipex->infile);
	close(pipex->pipefd[1]);
	execute_cmd(pipex, envp);
	free(pipex->cmd);
	pipex->cmd = 0;
}

void	change_fd_parent(t_pipex *pipex, char *argv[], char **envp)
{
	pipex->cmd = ft_split(argv[3], ' ');
	close(pipex->pipefd[1]);
	dup2(pipex->pipefd[0], STDIN_FILENO);
	dup2(pipex->outfile, STDOUT_FILENO);
	close(pipex->outfile);
	close(pipex->pipefd[0]);
	execute_cmd(pipex, envp);
	free(pipex->cmd);
	pipex->cmd = 0;
}

void	leaks(void)
{
	system("leaks pipex");
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;
	pid_t	pid1;

	atexit(leaks);
	pipex.infile = open(argv[1], O_RDONLY);
	pipex.outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (!sanity_check(argc, argv, &pipex))
		return (0);
	if (!check_fork(&pid1))
		return (0);
	if (pid1 == 0)
		change_fd_children(&pipex, argv, envp);
	else
		change_fd_parent(&pipex, argv, envp);
	close(pipex.infile);
	close(pipex.outfile);
	waitpid(pid1, NULL, 0);
	return (0);
}
