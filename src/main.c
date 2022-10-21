/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:19:09 by alfgarci          #+#    #+#             */
/*   Updated: 2022/10/21 12:54:49 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		i;
	int		infile;
	int		outfile;
	char	**last_cmd;

	if (ac < 5)
		return (error_bad_format());
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		outfile = open(av[ac -1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
		here_doc(av[2], ac);
		i = 3;
	}
	else
	{	
		if (access(av[1], F_OK) != 0)
			return (error_file_not_found((char *)av[1]));
		outfile = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
		infile = open(av[1], O_RDONLY, 0777);
		dup2(infile, STDIN_FILENO);
		i = 2;
	}
	while (i < ac -2)
		childs(get_cmd(av[i++], envp));
	dup2(outfile, STDOUT_FILENO);
	last_cmd = get_cmd(av[ac - 2], envp);
	if (execve(last_cmd[0], last_cmd, NULL) == -1)
		return (error_execve());
	return (0);
}