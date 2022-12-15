/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:22:25 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/15 18:37:23 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	here_doc(char **av, int ac, int *outfile)
{
	int		pipe_ends[2];
	char	*line;

	*outfile = open(av[ac - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
	pipe(pipe_ends);
	if (fork() == 0)
	{
		close(pipe_ends[0]);
		ft_printf("pipe heredoc> ");
		line = get_next_line(0);
		av[2] = ft_strjoin(av[2], "\n");
		while (ft_strncmp(line, av[2], ft_strlen(av[2]) + 1) != 0)
		{
			write(pipe_ends[1], line, ft_strlen(line));
			free(line);
			ft_printf("pipe heredoc> ");
			line = get_next_line(0);
		}
		free(line);
		exit(0);
	}
	close(pipe_ends[1]);
	dup2(pipe_ends[0], STDIN_FILENO);
	wait(NULL);
}
