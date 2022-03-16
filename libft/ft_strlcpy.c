/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbembnis <hbembnis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:54:24 by hbembnis          #+#    #+#             */
/*   Updated: 2021/11/29 15:39:46 by hbembnis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strlen(const char *str);

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	int				i;
	unsigned int	j;

	i = 0;
	j = ft_strlen(src);
	if (size > 0)
	{
		while ((src[i] != '\0') && (size > 0))
		{
			dest[i] = src[i];
			i++;
			size--;
		}
		if (size == 0)
			dest[i - 1] = '\0';
		else
			dest[i] = '\0';
	}
	return (j);
}
