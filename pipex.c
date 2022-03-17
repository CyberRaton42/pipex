/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbembnis <hbembnis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:27:25 by hbembnis          #+#    #+#             */
/*   Updated: 2022/03/17 16:33:01 by hbembnis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_cmd(char **argv, char **envp, int *pipefd)
{
	int	infile_fd;

	infile_fd = open(argv[1], O_RDONLY);
	if (infile_fd == -1)
		ft_error();
	dup2(pipefd[1], STDOUT_FILENO);
	dup2(infile_fd, STDIN_FILENO);
	close(pipefd[0]);
	
}

int	main(int argc, char **argv, char **envp)
{
	int	pipefd[2];
	pid_t	pid1;

	if (argc == 5)
	{
		if (pipe(pipefd) == -1)
			ft_error();
		pid1 = fork();
		if (pid1 == -1)
			ft_error();
		
	}
	else
		arg_error();
	get_path_env(envp);
}
