/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:01:57 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/15 20:05:50 by alfgarci         ###   ########.fr       */
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
		return (perror(cmd[0]));
	if (pid == 0)
	{
		close(pipe_ends[0]);
		dup2(pipe_ends[1], STDOUT_FILENO);
		if (execve(cmd[0], cmd, NULL ) == -1)
			return (perror(cmd[0]));
	}
	else
	{
		close(pipe_ends[1]);
		dup2(pipe_ends[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
	free_split(cmd);
}

void	pipex(int ac, char **av, char **envp)
{
	int		i;
	int		infile;
	int		outfile;
	char	**last_cmd;

	i = 2 + (ft_strncmp(av[1], "here_doc", 8) == 0);
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
		here_doc(av, ac, &outfile);
	else
	{
		if (access(av[1], F_OK | R_OK) != 0)
			return (perror(av[1]));
		outfile = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		infile = open(av[1], O_RDONLY);
		dup2(infile, STDIN_FILENO);
	}
	while (i < ac - 2)
		childs(get_cmd(av[i++], envp));
	last_cmd = get_cmd(av[ac - 2], envp);
	dup2(outfile, STDOUT_FILENO);
	if (execve(last_cmd[0], last_cmd, NULL) == -1)
	{
		free_split(last_cmd);
		return (perror(last_cmd[0]));
	}
}
