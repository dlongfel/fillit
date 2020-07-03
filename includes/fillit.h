/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlongfel <dlongfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:45:26 by dlongfel          #+#    #+#             */
/*   Updated: 2020/02/02 13:45:28 by dlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <stdio.h>

typedef struct			s_figure
{
	int					x[4];
	int					y[4];
	char				letter;
	struct s_figure		*next;
}						t_figure;

typedef struct			s_map
{
	int					map_size;
	char				**map;
}						t_map;

void					fault(void);
int						read_file(int fd);
void					validation(char *str, int count);
void					additional(char *str, int count);
void					dots_and_sharps(char *str);
void					offset(t_figure *list);
void					offset_help(t_figure *list, int code);
int						offset_up(t_figure *list);
int						offset_left(t_figure *list);
int						offset_down(t_figure *list, int size);
int						offset_right(t_figure *list, int size);
int						checkout(t_figure *piece, char **map, t_map *map1);
void					map_print(char **map, int size);
int						variation(t_figure *target, t_map *map, int on);
int						brute_force(t_figure *list, t_map *map);
t_figure				*create_list(int fd, int count);
void					free_list(t_figure *list);
void					coordinate(t_figure *list, char *str);
void					map_free(char **map, int size);
void					letter_placement(t_figure *list, t_map *map);
void					map_clear(char a, char **map, int size_map);
char					**map_make(int size);
void					map_add(t_map *map);
int						borders(t_figure *piece, int size);
int						check_letter(char a);

#endif
