/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 02:29:14 by alfgarci          #+#    #+#             */
/*   Updated: 2022/10/22 06:23:36 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**get_path(char **envp)
{
	int		i;
	int		j;
	char	**path;

	i = 0;
	j = 0;
	path = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_split(envp[i] + 5, ':');
			if (!path)
				return (NULL);
			while (path[j])
			{
				if (path[j][ft_strlen(path[j]) - 1] != '/')
					path[j] = ft_strjoin(path[j], "/");
				j++;
			}
			break ;
		}
		i++;
	}
	return (path);
}

int	check_path(char **cmd, char **envp)
{
	int		i;
	char	**path;
	char	*tmp;

	i = 0;
	path = get_path(envp);
	if (!path)
		return (0);
	while (path[++i])
	{
		tmp = ft_strjoin(path[i], *cmd);
		if (access(tmp, F_OK) == 0)
		{
			free(*cmd);
			*cmd = tmp;
			return (1);
		}
		free(tmp);
	}
	if (access(*cmd, F_OK) == 0)
		return (1);
	return (0);
}

char	**get_cmd(const char *arg_cmd, char **envp)
{
	char	**cmd;

	cmd = ft_split(arg_cmd, ' ');
	if (!cmd)
		return (NULL);
	if (!check_path(cmd, envp))
		return (NULL);
	return (cmd);
}
