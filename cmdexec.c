/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdexec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbembnis <hbembnis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:11:30 by hbembnis          #+#    #+#             */
/*   Updated: 2022/03/17 16:43:13 by hbembnis         ###   ########.fr       */
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
		ft_error("Malloc");
	while (path_tab[i])
	{
		usable_cmd = ft_strjoin("/", usable_cmd);
		path = ft_strjoin(path_tab[i], usable_cmd);
		if (access(path, X_OK) == 0)
			return (path)
		free(path);
		free(usable_cmd)
		i++; 
	}
	return (NULL);
}