/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlongfel <dlongfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:42:53 by dlongfel          #+#    #+#             */
/*   Updated: 2020/02/02 13:42:54 by dlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if ((!s1 || !s2) || ((n + 1) == 0))
		return (1);
	while ((s1[i] != '\0' || s2[i] != '\0') && i != n)
	{
		if (s1[i] != s2[i])
			return (0);
		else
			i++;
	}
	return (1);
}
