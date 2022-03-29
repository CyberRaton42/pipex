/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbembnis <hbembnis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:27:25 by hbembnis          #+#    #+#             */
/*   Updated: 2022/03/29 14:46:54 by hbembnis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	multi_cmd(char *argv, char **envp)
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
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		exec_cmd(argv, envp);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		waitpid(pid1, NULL, 0);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	infile_fd;
	int	outfile_fd;

	if (argc >= 5)
	{
		if (ft_strnstr(argv[1], "here_doc", 8) == 1)
		{
			i = 3;
			outfile_fd = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
			ft_here_doc(argv);
		}
		else
		{
			i = 2;
			infile_fd = open(argv[1], O_RDONLY);
			outfile_fd = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
			dup2(infile_fd, STDIN_FILENO);
		}
		while (i < (argc - 2))
			multi_cmd(argv[i++], envp);
		dup2(outfile_fd, STDOUT_FILENO);
		exec_cmd(argv[argc - 2], envp);
	}
	else
		arg_error();
}

/*int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	pid1;

	if (argc >= 5)
	{
		if (ft_strnstr(argv[1], "here_doc", 8) == 1)
			ft_here_doc(argv, argc);
		
	}
	else
		arg_error();
}*/
