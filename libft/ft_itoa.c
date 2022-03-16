/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbembnis <hbembnis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:52:23 by hbembnis          #+#    #+#             */
/*   Updated: 2021/12/12 11:28:31 by hbembnis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_reslen(int n)
{
	long	ncp;
	int		reslen;

	ncp = n;
	reslen = 0;
	if (ncp < 0)
	{
		ncp = ncp * -1;
		reslen++;
	}
	while (ncp >= 10)
	{
		reslen++;
		ncp = ncp / 10;
	}
	return (reslen);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	long	ncp;

	i = ft_reslen(n);
	ncp = n;
	if (n < 0)
		ncp = ncp * -1;
	res = malloc(sizeof(char) * i + 1);
	if (res == NULL)
		return (NULL);
	res[i + 1] = '\0';
	while (ncp >= 10)
	{
		res[i] = ncp % 10 + '0';
		ncp = ncp / 10;
		i--;
	}
	res[i] = ncp + '0';
	i--;
	if (n < 0)
		res[i] = '-';
	return (res);
}
