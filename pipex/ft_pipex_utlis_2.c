/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utlis_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:56:34 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/03/12 18:34:46 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

t_boolean	sanity_check(int argc, char *argv[], t_pipex *pipex)
{
	if (!check_argc(argc))
		return (FALSE);
	if (!check_access(argv))
		return (FALSE);
	if (!check_open(&pipex->infile) || !check_open(&pipex->outfile))
		return (FALSE);
	if (!check_pipe(pipex->pipefd))
		return (FALSE);
	return (TRUE);
}

char	*find_path(char *envp[])
{
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

void	free_split(char **str)
{
	char	**tmp;

	tmp = str;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(str);
}

char	*find_command_path(char *command, char *envp[])
{
	char	*path;
	char	*full_path;
	char	**paths;

	path = find_path(envp);
	paths = ft_split(path, ':');
	while (*paths)
	{
		full_path = ft_strjoin(*paths, "/");
		full_path = ft_strjoin(full_path, command);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		paths++;
	}
	free_split(paths);
	return (NULL);
}

void	execute_cmd(t_pipex *pipex, char **envp)
{
	char	*path;

	path = find_command_path(pipex->cmd[0], envp);
	if (!path)
	{
		perror("command not found");
		exit(1);
	}
	if (execve(path, pipex->cmd, envp) == ERROR)
	{
		perror("execve error");
		exit(1);
	}
}
