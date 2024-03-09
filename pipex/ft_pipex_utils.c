/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonwch <hyeonwch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:54:33 by hyeonwch          #+#    #+#             */
/*   Updated: 2024/03/09 23:03:42 by hyeonwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

t_boolean	check_access(char *str[])
{
	char	*file1;
	char	*file2;
	int		read;
    int     write;

	read = R_OK;
    write = W_OK;
	file1 = str[1];
	file2 = str[4];
	if (access( file1, read ) == ERROR)
	{
		perror("infile is not exist or permission denied.");
		return (FALSE);
	}
    if (access( file2, write ) == ERROR)
    {
        perror("outfile is not exist or permission denied.");
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

t_boolean	check_open(int *fd)
{
	if (*fd == ERROR)
	{
		perror("open error");
		return (FALSE);
	}
	return (TRUE);
}

t_boolean	check_pipe(int *pipefd)
{
	pipe(pipefd);
	if (*pipefd == ERROR || *(pipefd + 1) == ERROR)
	{
		perror("pipe error");
		return (FALSE);
	}
	return (TRUE);
}

t_boolean	check_fork(pid_t *pid)
{
	*pid = fork();
	if (*pid == ERROR)
	{
		perror("fork error");
		return (FALSE);
	}
	return (TRUE);
}