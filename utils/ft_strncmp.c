/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbembnis <hbembnis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:17:50 by hbembnis          #+#    #+#             */
/*   Updated: 2021/12/07 14:52:39 by hbembnis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *a, const char *b, size_t len)
{
	size_t	i;
	int		diff;

	i = 0;
	diff = 0;
	if (len == 0)
		return (diff);
	while (a[i] == b[i] && i < (len - 1) && a[i] != '\0' && b[i] != '\0')
		i++;
	diff = (unsigned char)a[i] - (unsigned char)b[i];
	return (diff);
}
