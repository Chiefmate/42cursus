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

void	end_game(t_game *g)
{
	mlx_destroy_window(g->mlx, g->wlx);
	exit(0);
}

void	clear_game(t_game *g)
{
	g->walk_cnt++;
	printf("Clear! Walked %d steps", g->walk_cnt);
	exit(0);
}

int	press_key(int key, t_game *game)
{
	if (key == KEY_W)
		move_w(game);
	else if (key == KEY_A)
		move_a(game);
	else if (key == KEY_S)
		move_s(game);
	else if (key == KEY_D)
		move_d(game);
	else if (key == KEY_ESC)
		end_game(game);
	return (0);
}
