/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbembnis <hbembnis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:27:25 by hbembnis          #+#    #+#             */
/*   Updated: 2022/03/24 16:18:02 by hbembnis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	second_cmd(char **argv, char **envp, int *pipefd)
{
	int	outfile_fd;

	outfile_fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile_fd == -1)
		ft_error();
	dup2(pipefd[0], STDIN_FILENO);
	dup2(outfile_fd, STDOUT_FILENO);
	close(pipefd[0]);
	if (exec_cmd(argv[3], envp) == 0)
		return (0);
	return (1);
}

int	first_cmd(char **argv, char **envp, int *pipefd)
{
	int		infile_fd;
	pid_t	pid2;

	pid2 = fork();
	if (pid2 == -1)
		ft_error();
	if (pid2 == 0)
	{
		ft_putstr_fd("child2", 2);
		if (second_cmd(argv, envp, pipefd) == 0)
			return (0);
	}
	else
	{
		infile_fd = open(argv[1], O_RDONLY);
		if (infile_fd == -1)
			ft_error();
		dup2(pipefd[1], STDOUT_FILENO);
		dup2(infile_fd, STDIN_FILENO);
		//close(pipefd[1]);
		if (exec_cmd(argv[2], envp) == 0)
			return (0);
	}
	return (1);
}

void	ft_close(int *pipefd)
{
	close(pipefd[0]);
	close(pipefd[1]);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	pid1;
	//pid_t	pid2;

	if (argc == 5)
	{
		if (pipe(pipefd) == -1)
			ft_error();
		pid1 = fork();
		if (pid1 == -1)
			ft_error();
		if (pid1 == 0)
		{
			ft_putstr_fd("child1", 2);
			if (first_cmd(argv, envp, pipefd) == 0)
				return (127);
		}
		/*read(pipefd[0], "", 0);
		pid2 = fork();
		if (pid2 == -1)
			ft_error();
		if (pid2 == 0)
		{
			//ft_putstr_fd("child2", 2);
			if (second_cmd(argv, envp, pipefd) == 0)
				return (127);
		}*/
		waitpid(pid1, NULL, 0);
		//ft_close(pipefd);
	}
	else
		arg_error();
	return (0);
}
