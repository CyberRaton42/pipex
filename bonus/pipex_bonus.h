/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbembnis <hbembnis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:29:26 by hbembnis          #+#    #+#             */
/*   Updated: 2022/03/29 14:47:01 by hbembnis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H 

# include "../utils/utils.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>

char	*get_path_env(char **envp);
int		exec_cmd(char *argv, char **envp);
void	free_tab(char **tab);
void	ft_error(void);
void	arg_error(void);
void	ft_here_doc(char **argv);

#endif