/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlongfel <dlongfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:43:18 by dlongfel          #+#    #+#             */
/*   Updated: 2020/02/02 13:43:19 by dlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countword(char const *s, char c)
{
	int count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s != c && *s != '\0')
				s++;
		}
		else
			s++;
	}
	return (count);
}

static int		ft_wordmalloc(char const *s, char c, char **mass)
{
	int lenword;
	int i;

	i = 0;
	while (*s)
	{
		lenword = 0;
		if (*s != c)
		{
			while (*s != c && *s != '\0')
			{
				s++;
				lenword++;
			}
			if (!(mass[i++] = ((char *)malloc(sizeof(char) * (lenword + 1)))))
				return (i);
		}
		else
			s++;
	}
	return (0);
}

static void		ft_rewriting(char const *s, char c, char **mass)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s != c && *s != '\0')
				mass[i][j++] = *s++;
			mass[i++][j] = '\0';
		}
		j = 0;
		if (*s != '\0')
			s++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	int		word;
	char	**mass;
	int		res;

	if (!s || !c)
		return (NULL);
	word = ft_countword(s, c);
	if (!(mass = (char **)malloc(sizeof(char *) * (word + 1))))
		return (0);
	mass[word] = NULL;
	res = ft_wordmalloc(s, c, mass);
	if (res == 0)
		ft_rewriting(s, c, mass);
	else
	{
		while (res != 0)
		{
			free(mass[res]);
			mass[res--] = NULL;
		}
		free(mass);
	}
	return ((char **)mass);
}
