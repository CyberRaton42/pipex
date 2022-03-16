/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbembnis <hbembnis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:51:55 by hbembnis          #+#    #+#             */
/*   Updated: 2021/11/26 14:58:55 by hbembnis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (c < 48 || c > 57)
	{
		if (c < 65 || c > 90)
		{
			if (c < 97 || c > 122)
				return (0);
		}
	}
	return (1);
}