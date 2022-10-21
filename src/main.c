/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:19:09 by alfgarci          #+#    #+#             */
/*   Updated: 2022/10/21 17:23:33 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **envp)
{
	if (ac >= 5 )
		pipex(ac, av, envp);
	else
	{
		ft_printf("error: wrong number of parameters.\n");
		return (-1);
	}
	return (0);
}
