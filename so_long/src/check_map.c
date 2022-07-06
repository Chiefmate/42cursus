/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 09:38:23 by hyunhole          #+#    #+#             */
/*   Updated: 2022/07/06 11:23:12 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	wall_check_map(t_map *map);
static void	valid_check_map(t_map *map);

void	check_map(t_map *map)
{
	if (map->width * map->height != (int)ft_strlen(map->info))
		ft_exit_error("NOT rectangular map\n");
	wall_check_map(map);
	valid_check_map(map);
	return ;
}

static void	wall_check_map(t_map *map)
{
	int	i;

	i = -1;
	while (++i < (int)ft_strlen(map->info))
	{
		if (map->info[i] != '1')
		{
			if (i < map->width)
				ft_exit_error("NOT surrounded by wall\n");
			else if (i % map->width == 0 || i % map->width == map->width - 1)
				ft_exit_error("NOT surrounded by wall\n");
			else if (i > (int)ft_strlen(map->info) - map->width)
				ft_exit_error("NOT surrounded by wall\n");
		}
	}
	return ;
}

static void	valid_check_map(t_map *map)
{
	int	i;
	int	exit_num;
	int	play_num;

	i = -1;
	exit_num = 0;
	play_num = 0;
	map->num_col = 0;
	while (++i < (int)ft_strlen(map->info))
	{
		if (map->info[i] == 'E')
			exit_num++;
		else if (map->info[i] == 'P')
			play_num++;
		else if (map->info[i] == 'C')
			map->num_col += 1;
	}
	if (!exit_num)
		ft_exit_error("No exit on the map\n");
	if (map->num_col == 0)
		ft_exit_error("No collectible on the map\n");
	if (play_num != 1)
		ft_exit_error("Player must exist and be only one\n");
	return ;
}
