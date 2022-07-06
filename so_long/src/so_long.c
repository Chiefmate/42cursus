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

int	ft_exit_error(char *m)
{
	write(2, "Error\n", 6);
	write(2, m, ft_strlen(m));
	exit(1);
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->wlx);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_map	map;
	t_game	*game;

	if (argc <= 1 || argc > 2)
		return (0);
	load_map(argv[1], &map);
	check_map(map);
	game = make_game(map);
	map_to_img(map, *game);
	mlx_hook(game->wlx, X_EVENT_KEY_RELEASE, 0, &get_pressed_key, game);
	mlx_hook(game->wlx, X_EVENT_KEY_EXIT, 0, &exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}
