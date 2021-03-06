/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbembnis <hbembnis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:14:53 by hbembnis          #+#    #+#             */
/*   Updated: 2022/03/29 14:14:53 by hbembnis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	get_cmd_line(char **cmd_line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	r = 0;
	buffer = malloc(sizeof(char *) * 5000);
	if (!buffer)
		ft_error();
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[i + 1] = '\0';
	*cmd_line = buffer;
	free(buffer);
	return (r);
}

void	ft_here_doc(char **argv)
{
	pid_t	pid_here;
	int		pipefd[2];
	char	*cmd_line;

	if (pipe(pipefd) == -1)
		ft_error();
	pid_here = fork();
	if (pid_here == 0)
	{
		close(pipefd[0]);
		ft_putstr_fd("pipe heredoc> ", 1);
		while (get_cmd_line(&cmd_line))
		{
			if (ft_strnstr(cmd_line, argv[2], ft_strlen(argv[2])) == 1)
				exit(EXIT_SUCCESS);
			ft_putstr_fd("pipe heredoc> ", 1);
			ft_putstr_fd(cmd_line, pipefd[1]);
		}
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		wait(NULL);
	}
}
