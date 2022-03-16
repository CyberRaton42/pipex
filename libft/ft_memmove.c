/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbembnis <hbembnis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:18:14 by hbembnis          #+#    #+#             */
/*   Updated: 2021/12/08 13:19:12 by hbembnis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (n > 0)
		{
			n--;
			*(char *)(dst + n) = *(const char *)(src + n);
		}
	}
	else
	{
		while (i < n)
		{
			*(char *)(dst + i) = *(const char *)(src + i);
			i++;
		}
	}
	return (dst);
}
