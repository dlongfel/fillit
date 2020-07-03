/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlongfel <dlongfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:36:48 by dlongfel          #+#    #+#             */
/*   Updated: 2020/02/02 13:36:49 by dlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	map_add(t_map *map)
{
	map_free(map->map, map->map_size);
	map->map_size = map->map_size + 1;
	map->map = map_make(map->map_size);
}

void	letter_placement(t_figure *list, t_map *map)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map->map[list->y[i]][list->x[i]] = list->letter;
		i++;
	}
}

void	map_print(char **map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putstr(map[i]);
		ft_putstr("\n");
		i++;
	}
}

void	map_clear(char a, char **map, int size_map)
{
	int i;
	int x;

	x = 0;
	i = 0;
	while (x < size_map)
	{
		if (map[x][i] == a)
			map[x][i] = '.';
		i++;
		if (i == size_map)
		{
			i = 0;
			x++;
		}
	}
}

char	**map_make(int size)
{
	char	**map;
	int		i;

	map = (char**)malloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		map[i] = (char*)ft_memalloc(size + 1);
		map[i] = ft_memset(map[i], 46, size);
		i++;
	}
	return (map);
}
