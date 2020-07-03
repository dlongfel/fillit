/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlongfel <dlongfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:42:05 by dlongfel          #+#    #+#             */
/*   Updated: 2020/02/02 13:42:07 by dlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t j;
	size_t i;

	i = 0;
	j = 0;
	while (dst[j] != '\0' && j < size)
		j++;
	while ((src[i] != '\0') && (j + 1 < size))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	if (j < size)
		dst[j] = '\0';
	return ((size_t)(ft_strlen(src) + j - i));
}
