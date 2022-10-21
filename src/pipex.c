/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:01:57 by alfgarci          #+#    #+#             */
/*   Updated: 2022/10/21 12:44:18 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	childs(char **cmd)
{
	int	pid;
	int	pipe_ends[2];

	pipe(pipe_ends);
	pid = fork();
	if (pid == -1)
		return (perror("Could not execute fork"));
	if (pid == 0)
	{
		close(pipe_ends[0]);
		dup2(pipe_ends[1], STDOUT_FILENO);
		if (execve(cmd[0], cmd, NULL ) == -1)
			return (perror("Could not execute execve"));
	}
	else
	{
		close(pipe_ends[1]);
		dup2(pipe_ends[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}
