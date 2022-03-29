/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbembnis <hbembnis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:05:36 by hbembnis          #+#    #+#             */
/*   Updated: 2022/03/29 14:25:40 by hbembnis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_error(void)
{
	perror(NULL);
	exit(EXIT_FAILURE);
}

void	arg_error(void)
{
	ft_putstr_fd("Error : Bad Arguments \n", 2);
	ft_putstr_fd("Expected : ./pipex_bonus file1 cmd1 cmd2 ... cmdn file2", 1);
	ft_putstr_fd("Expected : ./pipex_bonus here_doc LIMITER cmd cmd1 file", 1);
	exit(EXIT_FAILURE);
}
