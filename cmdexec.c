/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdexec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbembnis <hbembnis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:11:30 by hbembnis          #+#    #+#             */
/*   Updated: 2022/03/16 17:42:23 by hbembnis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path_env(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	while (ft_strncmp("PATH", envp[i], 5) != 0)
		i++;
	path = ft_strdup(envp[i]);
	printf("%s\n", path);
	return (path);
}
