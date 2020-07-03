/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlongfel <dlongfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:39:53 by dlongfel          #+#    #+#             */
/*   Updated: 2020/02/02 13:39:54 by dlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = (char *)dst;
	s = (const char *)src;
	i = 0;
	if (s > d)
	{
		while (i != len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (s < d)
	{
		while (len-- != 0)
			d[len] = s[len];
	}
	return ((void *)d);
}
