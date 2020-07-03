/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlongfel <dlongfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:36:36 by dlongfel          #+#    #+#             */
/*   Updated: 2020/02/02 13:36:38 by dlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		coordinate(t_figure *list, char *str)
{
	int x;
	int y;
	int i;
	int pos;

	x = 0;
	y = 0;
	i = 0;
	pos = 0;
	str[22] = '\0';
	while (str[i])
	{
		if (str[i] == '\n')
			y++;
		if (str[i] == '#')
		{
			list->y[pos] = y;
			list->x[pos] = x;
			pos++;
		}
		x++;
		if (x == 5)
			x = 0;
		i++;
	}
}

void		free_list(t_figure *list)
{
	t_figure *buff;

	while (list)
	{
		buff = list;
		list = list->next;
		free(buff);
	}
}

t_figure	*create_list(int fd, int count)
{
	t_figure	*new;
	t_figure	*first;
	char		buff[22];
	int			i;

	i = 1;
	ft_bzero(buff, 22);
	new = (t_figure *)malloc(sizeof(t_figure));
	first = new;
	while (read(fd, buff, 21) && i <= count)
	{
		coordinate(new, buff);
		new->letter = '@' + i;
		if (i == count)
			new->next = NULL;
		else
		{
			new->next = (t_figure *)malloc(sizeof(t_figure));
			new = new->next;
			i++;
		}
	}
	close(fd);
	return (first);
}
