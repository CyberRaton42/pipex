/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbembnis <hbembnis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:54:06 by hbembnis          #+#    #+#             */
/*   Updated: 2021/12/08 14:02:03 by hbembnis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_inset(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_start(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (ft_inset(s1[i], set) == 1)
		i++;
	return (i);
}

static int	ft_end(const char *s1, const char *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (ft_inset(s1[i], set) == 1)
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		i;
	int		start;
	int		end;

	if (!s1)
		return (NULL);
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	i = 0;
	dest = malloc(sizeof(char) * end + 1);
	if (dest == NULL)
		return (NULL);
	while (i + start <= end)
	{
		dest[i] = s1[i + start];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
