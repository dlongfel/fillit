/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkout.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlongfel <dlongfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:36:20 by dlongfel          #+#    #+#             */
/*   Updated: 2020/02/02 13:36:21 by dlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_letter(char a)
{
	if (a >= 'A' && a <= 'Z')
		return (1);
	return (0);
}

int		borders(t_figure *list, int size)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (list->y[i] >= size)
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (list->x[i] >= size)
			return (0);
		i++;
	}
	return (1);
}

int		checkout(t_figure *list, char **map, t_map *map1)
{
	int i;

	i = 0;
	if (borders(list, map1->map_size))
	{
		while (i < 4)
		{
			if (check_letter(map[list->y[i]][list->x[i]]))
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
