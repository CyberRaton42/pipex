/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbembnis <hbembnis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:05:36 by hbembnis          #+#    #+#             */
/*   Updated: 2022/04/07 14:59:31 by hbembnis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(void)
{
	perror(NULL);
	exit(EXIT_FAILURE);
}

int	cmd_error(void)
{
	ft_putstr_fd("Command not found\n", 2);
	return (127);
	//exit(EXIT_FAILURE);
}

void	arg_error(void)
{
	ft_putstr_fd("Error : Bad Arguments \n", 2);
	ft_putstr_fd("Expected : ./pipex file1 cmd1 cmd2 file2", 1);
}
