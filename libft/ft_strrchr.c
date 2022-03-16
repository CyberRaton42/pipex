/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbembnis <hbembnis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:15:39 by hbembnis          #+#    #+#             */
/*   Updated: 2021/12/08 13:39:24 by hbembnis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*lastpos;

	i = 0;
	lastpos = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			lastpos = (char *)(str + i);
		i++;
	}
	if (str[i] == (unsigned char)c)
		lastpos = (char *)(str + i);
	if (lastpos == 0)
		return (NULL);
	return (lastpos);
}
