/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbembnis <hbembnis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:25:30 by hbembnis          #+#    #+#             */
/*   Updated: 2021/11/29 14:38:05 by hbembnis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t count, size_t size)
{
	char	*membloc;

	membloc = malloc(count * size);
	if (membloc == NULL)
		return (NULL);
	ft_bzero(membloc, count * size);
	return (membloc);
}
