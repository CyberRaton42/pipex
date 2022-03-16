/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbembnis <hbembnis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:17:57 by hbembnis          #+#    #+#             */
/*   Updated: 2021/12/08 13:19:42 by hbembnis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		*(char *)(dst + i) = *(const char *)(src + i);
		i++;
	}
	return (dst);
}
