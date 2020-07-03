/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlongfel <dlongfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:38:12 by dlongfel          #+#    #+#             */
/*   Updated: 2020/02/02 13:38:13 by dlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numcount(int number, int counter)
{
	while (number / 10 != 0)
	{
		counter++;
		number = number / 10;
	}
	return (counter);
}

char		*ft_itoa(int n)
{
	char			*str;
	int				i;
	unsigned int	dub;

	i = (n < 0 ? 2 : 1);
	i = ft_numcount(n, i);
	if (n < 0)
		dub = -n;
	else
		dub = n;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	while (i >= 0)
	{
		n = dub % 10;
		str[i--] = (n + '0');
		dub = dub / 10;
	}
	if (str[0] == '0' && str[1] != '\0')
		str[0] = '-';
	return ((char *)str);
}
