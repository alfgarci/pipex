/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:30:49 by alfgarci          #+#    #+#             */
/*   Updated: 2022/10/21 12:54:52 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	error_bad_format(void)
{
	ft_printf("error: wrong number of parameters.\n");
	return (-1);
}

int	error_file_not_found(char *name)
{
	ft_printf("error: no such file or directory: %s\n", (char *)av[1]);
	return (-1);
}

int	error_execve(void)
{
	ft_printf("Could not execute execve.\n");
	return (-1);
}

int	error_fork(void)
{
	ft_printf("Could not execute fork.\n");
	return (-1);
}
