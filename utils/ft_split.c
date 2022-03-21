/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbembnis <hbembnis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:18:38 by hbembnis          #+#    #+#             */
/*   Updated: 2022/03/18 15:59:02 by hbembnis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_count(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i + 1] != '\0')
				i++;
		}
		i++;
	}
	return (count);
}

static int	ft_wordlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c)
	{
		i++;
		if (s[i] == '\0')
			return (i);
	}
	return (i);
}

static char	*ft_dup(char const *s, char c)
{
	int		i;
	char	*word;

	i = 0;
	word = (char *)malloc(sizeof(char) * (ft_wordlen(s, c) + 1));
	if (word == NULL)
		return (NULL);
	while (s[i] != c)
	{
		word[i] = s[i];
		i++;
		if (s[i] == '\0')
		{
			word[i] = '\0';
			return (word);
		}
	}
	word[i] = '\0';
	return (word);
}

static void	ft_free(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			tab[j] = ft_dup(&s[i], c);
			if (tab[j] == NULL)
				ft_free(tab, j);
			while (s[i] != c && s[i] != '\0')
				i++;
			j++;
		}
		else
			i++;
	}
	tab[j] = 0;
	return (tab);
}
