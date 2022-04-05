/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdexec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbembnis <hbembnis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:11:30 by hbembnis          #+#    #+#             */
/*   Updated: 2022/04/05 15:49:45 by hbembnis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path_env(char **envp)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	j = 0;
	while (ft_strnstr(envp[i], "PATH", 4) != 1)
		i++;
	path = ft_strdup(envp[i]);
	if (!path)
		ft_error();
	i = 5;
	while (path[i])
	{
		path[j] = path[i];
		i++;
		j++;
	}
	path[j] = '\0';
	return (path);
}

char	*get_exec_path(char *full_path, char *cmd)
{
	char	**path_tab;
	char	*path;
	char	*usable_cmd;
	int		i;

	i = 0;
	path_tab = ft_split(full_path, ':');
	if (!path_tab)
		ft_error();
	while (path_tab[i])
	{
		usable_cmd = ft_strjoin("/", cmd);
		path = ft_strjoin(path_tab[i], usable_cmd);
		if (access(path, X_OK) == 0)
		{
			free_tab(path_tab);
			free(usable_cmd);
			return (path);
		}
		free(path);
		free(usable_cmd);
		i++;
	}
	free_tab(path_tab);
	return (NULL);
}

int	exec_cmd(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = get_exec_path(get_path_env(envp), cmd[0]);
	if (access(cmd[0], X_OK) == 0)
		path = cmd[0];
	if (!path)
	{
		free_tab(cmd);
		cmd_not_found();
		return (127);
	}
	if (execve(path, cmd, envp) == -1)
		ft_error();
	return (1);
}
