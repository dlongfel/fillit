/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlongfel <dlongfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:39:58 by dlongfel          #+#    #+#             */
/*   Updated: 2020/02/02 13:39:58 by dlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;
	size_t	counter;

	str = (char *)b;
	counter = 0;
	while (counter != len)
	{
		str[counter] = (char)c;
		counter++;
	}
	return ((void *)str);
}
