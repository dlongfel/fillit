/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlongfel <dlongfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:42:21 by dlongfel          #+#    #+#             */
/*   Updated: 2020/02/02 13:42:22 by dlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*newstr;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(newstr = (char *)malloc(sizeof(*s) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[i] != '\0')
	{
		newstr[i] = f(s[i]);
		i++;
	}
	newstr[i] = '\0';
	return ((char *)newstr);
}
