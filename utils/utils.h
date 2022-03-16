/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbembnis <hbembnis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:22:13 by hbembnis          #+#    #+#             */
/*   Updated: 2022/03/16 17:41:34 by hbembnis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>

void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *a, const char *b, size_t len);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *src);

#endif