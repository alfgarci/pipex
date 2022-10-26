/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:25:47 by alfgarci          #+#    #+#             */
/*   Updated: 2022/10/25 13:13:24 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include "../libft/includes/libft.h"

void	pipex(int ac, char **av, char **envp);
char	**get_cmd(const char *arg_cmd, char **envp);
void	here_doc(char **av, int ac, int *outfile);

#endif
