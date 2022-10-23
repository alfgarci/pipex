/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:22:25 by alfgarci          #+#    #+#             */
/*   Updated: 2022/10/23 02:54:32 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	here_doc(char *limit, int ac)
{
	int		pipe_ends[2];
	char	*line;

	if (ac < 6)
		return (perror("Bad format.\n"));
	pipe(pipe_ends);
	if (fork() == 0)
	{
		close(pipe_ends[0]);
		ft_printf("pipe heredoc> ");
		line = get_next_line(0);
		while (ft_strncmp(line, limit, ft_strlen(limit) - 1) != 0)
		{
			ft_printf("pipe heredoc> ");
			line = get_next_line(0);
			write(pipe_ends[1], line, ft_strlen(line));
		}
		free(line);
		exit(0);
	}
	else
	{
		close(pipe_ends[1]);
		dup2(pipe_ends[0], STDIN_FILENO);
		wait(NULL);
	}
}
