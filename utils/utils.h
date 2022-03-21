/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbembnis <hbembnis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:22:13 by hbembnis          #+#    #+#             */
/*   Updated: 2022/03/18 16:00:10 by hbembnis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>

void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *a, const char *b, size_t len);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *src);
int 	ft_strnstr(const char	*big, const char *little, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int	ft_strlen(const char *str);

#endif