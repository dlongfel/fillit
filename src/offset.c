/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlongfel <dlongfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:36:53 by dlongfel          #+#    #+#             */
/*   Updated: 2020/02/02 13:36:54 by dlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	offset_help(t_figure *list, int code)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (code == 1)
			list->x[i] = list->x[i] + 1;
		if (code == 2)
			list->y[i] = list->y[i] + 1;
		i++;
	}
}

int		offset_right(t_figure *list, int size)
{
	int i;
	int max;

	i = 0;
	max = -1;
	while (i < 4)
	{
		if (list->x[i] > max)
			max = list->x[i];
		if (list->x[i] + 1 == size)
		{
			max = 99;
			break ;
		}
		i++;
	}
	if (max != 99)
	{
		offset_help(list, 1);
		return (1);
	}
	return (0);
}

int		offset_down(t_figure *list, int size)
{
	int i;
	int min;

	i = 0;
	min = 10;
	while (i < 4)
	{
		if (list->y[i] < min)
			min = list->y[i];
		if (list->y[i] + 1 >= size)
		{
			min = 99;
			break ;
		}
		i++;
	}
	if (min != 99)
	{
		offset_help(list, 2);
		return (1);
	}
	return (0);
}

int		offset_left(t_figure *list)
{
	int i;
	int min;
	int tmp;

	i = 0;
	min = 99;
	while (i < 4)
	{
		if (list->x[i] < min)
			min = list->x[i];
		i++;
	}
	if (min != 99)
	{
		i = 0;
		while (i < 4)
		{
			tmp = list->x[i] - min;
			list->x[i] = tmp;
			i++;
		}
		return (1);
	}
	return (0);
}

int		offset_up(t_figure *list)
{
	int i;
	int min;

	i = 0;
	min = 99;
	while (i < 4)
	{
		if (list->y[i] < min)
			min = list->y[i];
		i++;
	}
	i = 0;
	if (min != 99)
	{
		while (i < 4)
		{
			list->y[i] = list->y[i] - min;
			i++;
		}
		return (1);
	}
	return (0);
}
