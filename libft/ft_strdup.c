/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlongfel <dlongfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:41:35 by dlongfel          #+#    #+#             */
/*   Updated: 2020/02/02 13:41:36 by dlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	if ((!(s2 = (char *)malloc(sizeof(*s1) * len + 1)))\
			|| ((len + 1) == 0) || (!s1))
		return (NULL);
	while (i <= len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return ((char *)s2);
}
