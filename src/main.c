/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:19:09 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/15 20:10:26 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **envp)
{
	if (!*envp)
	{
		ft_printf("error: No env\n");
		return (-1);
	}
	if (ac < 2)
	{
		ft_printf("error: Wrong number of parameters\n");
		return (-1);
	}
	if (((!ft_strncmp(av[1], "here_doc", 8)) && ac >= 6)
		|| ((ft_strncmp(av[1], "here_doc", 8)) && ac >= 5))
		pipex(ac, av, envp);
	else
	{
		ft_printf("error: Wrong number of parameters\n");
		return (-1);
	}
	return (0);
}
