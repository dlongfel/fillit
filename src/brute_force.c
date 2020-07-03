/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_force.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlongfel <dlongfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:36:11 by dlongfel          #+#    #+#             */
/*   Updated: 2020/02/02 13:36:13 by dlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		variation(t_figure *list, t_map *map, int code)
{
	if (!list)
		return (0);
	else if (code == 7)
		offset(list);
	else if (code)
	{
		while (list)
		{
			offset(list);
			list = list->next;
		}
		return (1);
	}
	else
	{
		if (!offset_right(list, map->map_size))
		{
			if (!offset_down(list, map->map_size))
				return (0);
			else
				offset_left(list);
		}
	}
	return (1);
}

int		brute_force(t_figure *list, t_map *map)
{
	int i;

	i = 0;
	if (!list)
		return (1);
	while (i < ((map->map_size - 1) * (map->map_size - 1)))
	{
		if (checkout(list, map->map, map))
		{
			letter_placement(list, map);
			if (brute_force(list->next, map))
				return (1);
			else
			{
				map_clear(list->letter, map->map, map->map_size);
				variation(list, map, 0);
				variation(list->next, map, 7);
			}
		}
		else if (!variation(list, map, 0))
			variation(list, map, 7);
		i++;
	}
	return (0);
}
