/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlongfel <dlongfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:36:42 by dlongfel          #+#    #+#             */
/*   Updated: 2020/02/02 13:36:43 by dlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	offset(t_figure *list)
{
	offset_up(list);
	offset_left(list);
}

void	map_free(char **map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}

void	start(t_figure *list, t_map *map)
{
	while (!brute_force(list, map))
	{
		map_add(map);
		variation(list, map, 1);
	}
	map_print(map->map, map->map_size);
	map_free(map->map, map->map_size);
	free(map);
}

void	fault(void)
{
	write(1, "error\n", 6);
	exit(0);
}

int		main(int argc, char **argv)
{
	t_figure	*first;
	t_map		*map;
	int			count;

	if (argc == 2)
	{
		count = read_file(open(argv[1], O_RDONLY));
		first = create_list(open(argv[1], O_RDONLY), count);
		map = (t_map*)malloc(sizeof(t_map));
		map->map_size = 2;
		map->map = map_make(map->map_size);
		variation(first, map, 1);
		start(first, map);
		free_list(first);
	}
	else
		write(1, "usage: ./fillit input_file\n", 27);
	return (0);
}
