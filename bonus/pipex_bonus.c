/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbembnis <hbembnis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:27:25 by hbembnis          #+#    #+#             */
/*   Updated: 2022/04/08 12:33:35 by hbembnis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	first_child( char *argv, char **envp, int infile_fd)
{
	pid_t	pid1;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		ft_error();
	pid1 = fork();
	if (pid1 == -1)
		ft_error();
	if (pid1 == 0)
	{
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		waitpid(pid1, NULL, 0);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		if (infile_fd == 0)
			exit(1);
		else
			exec_cmd(argv, envp);
	}	
}

void	no_heredoc(char **argv, char **envp, int outfile_fd)
{
	int	infile_fd;

	infile_fd = open(argv[1], O_RDONLY);
	dup2(infile_fd, 0);
	dup2(outfile_fd, 1);
	first_child(argv[2], envp, infile_fd);
}

int	main(int argc, char **argv, char **envp)
{
	int	out_fd;
	int	i;

	i = 3;
	if (argc >= 5)
	{
		if (ft_strnstr(argv[1], "here_doc", 8) == 1)
		{
			if (argc < 6)
				arg_error();
			out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
			ft_here_doc(argv);
		}
		else
			out_fd = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		no_heredoc(argv, envp, out_fd);
		while (i < argc - 2)
			first_child(argv[i++], envp, 1);
		exec_cmd(argv[i], envp);
	}
	else
		arg_error();
	return (0);
}
