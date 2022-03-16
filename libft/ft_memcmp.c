/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbembnis <hbembnis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:49:31 by hbembnis          #+#    #+#             */
/*   Updated: 2021/11/26 18:00:56 by hbembnis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t size)
{
	size_t				i;
	const unsigned char	*sptr1;
	const unsigned char	*sptr2;

	i = 0;
	sptr1 = (const unsigned char *)ptr1;
	sptr2 = (const unsigned char *)ptr2;
	while (i < size)
	{
		if (sptr1[i] != sptr2[i])
			return (sptr1[i] - sptr2[i]);
		i++;
	}
	return (0);
}
