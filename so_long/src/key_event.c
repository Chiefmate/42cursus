/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:11:35 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/27 20:21:34 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_coord(t_coord *param)
{
	param->x = 0;
	param->y = 0;
	return ;
}

void	end_game(t_map *m, t_game *g)
{

	mlx_destroy_window(g->mlx, g->wlx);
	exit(0);
}

int	press_key(int key, t_map *map, t_game *game)
{
	if (key == KEY_W)
		move_w(map, game);
	else if (key == KEY_A)
		move_a(map, game);
	else if (key == KEY_S)
		move_s(map, game);
	else if (key == KEY_D)
		move_d(map, game);
	else if (key == KEY_ESC)
		end_game(map, game);
	return (0);
}
