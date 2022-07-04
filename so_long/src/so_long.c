/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:28:48 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/27 21:01:52 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_coord	param;
	t_map	map;
	t_game	*game;

	if (argc <= 1 || argc > 2)
		return (0);
	load_map(argv[1], &map);
	game = make_game(map);
	map_to_img(map, *game);

	init_coord(&param);

	mlx_hook(game->wlx, X_EVENT_KEY_RELEASE, 0, get_pressed_key, &param);
	mlx_loop(game->mlx);
	return (0);
}
