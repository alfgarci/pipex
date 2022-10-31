/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:01:57 by alfgarci          #+#    #+#             */
/*   Updated: 2022/10/31 20:29:53 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	childs(char **cmd)
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

void	pipex(int ac, char **av, char **envp)
{
	int		i;
	int		infile;
	int		outfile;
	char	**last_cmd;

	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		here_doc(av, ac, &outfile);
		i = 3;
	}
	else
	{
		if (access(av[1], F_OK) != 0)
			return (perror("error: input file not found."));
		outfile = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		infile = open(av[1], O_RDONLY);
		dup2(infile, STDIN_FILENO);
		i = 2;
	}
	while (i < ac -2)
		childs(get_cmd(av[i++], envp));
	last_cmd = get_cmd(av[ac - 2], envp);
	dup2(outfile, STDOUT_FILENO);
	if (execve(last_cmd[0], last_cmd, NULL) == -1)
		return (perror("Could not execute execve."));
}
