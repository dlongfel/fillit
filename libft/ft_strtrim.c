/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlongfel <dlongfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:43:35 by dlongfel          #+#    #+#             */
/*   Updated: 2020/02/02 13:43:36 by dlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	while (s[i])
		i++;
	while (*s && ((s[i - 1] == ' ') || (s[i - 1] == '\t')\
				|| (s[i - 1] == '\n')))
		i--;
	if (!(str = (char *)malloc(sizeof(*s) * i + 1)))
		return (NULL);
	str[i] = '\0';
	while (i--)
		str[i] = s[i];
	return ((char *)str);
}
