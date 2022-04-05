/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbembnis <hbembnis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:05:36 by hbembnis          #+#    #+#             */
/*   Updated: 2022/04/05 13:24:03 by hbembnis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(void)
{
	perror(NULL);
	exit(EXIT_FAILURE);
}

void	arg_error(void)
{
	ft_putstr_fd("Error : Bad Arguments \n", 2);
	ft_putstr_fd("Expected : ./pipex file1 cmd1 cmd2 file2", 1);
}
