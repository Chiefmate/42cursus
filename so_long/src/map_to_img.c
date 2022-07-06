/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:07:51 by hyunhole          #+#    #+#             */
/*   Updated: 2022/07/06 10:07:22 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*make_game(t_map *map)
{
	t_game	*ret;
	int		img_width;
	int		img_height;

	ret = (t_game *)malloc(sizeof(t_game));
	ret->mlx = mlx_init();
	ret->wlx = mlx_new_window(ret->mlx, map->width * 64, map->height * 64, "so_long");
	ret->l_map = map;
	(ret->img).empty = mlx_xpm_file_to_image(ret->mlx, "./asset/empty.xpm", &img_width, &img_height);	
	(ret->img).wall = mlx_xpm_file_to_image(ret->mlx, "./asset/wall.xpm", &img_width, &img_height);
	(ret->img).player = mlx_xpm_file_to_image(ret->mlx, "./asset/player.xpm", &img_width, &img_height);
	(ret->img).collectible = mlx_xpm_file_to_image(ret->mlx, "./asset/collectible.xpm", &img_width, &img_height);
	(ret->img).exit = mlx_xpm_file_to_image(ret->mlx, "./asset/exit.xpm", &img_width, &img_height);
	return (ret);
}

void	map_to_img(t_game game)
{
	int		x;
	int		y;
	t_map	*map;

	map = game.l_map;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->info[y * map->width + x] == '0')
				mlx_put_image_to_window(game.mlx, game.wlx, game.img.empty, x * 64, y * 64);
			else if (map->info[y * map->width + x] == '1')
				mlx_put_image_to_window(game.mlx, game.wlx, game.img.wall, x * 64, y * 64);
			else if (map->info[y * map->width + x] == 'P')
				mlx_put_image_to_window(game.mlx, game.wlx, game.img.player, x * 64, y * 64);
			else if (map->info[y * map->width + x] == 'C')
				mlx_put_image_to_window(game.mlx, game.wlx, game.img.collectible, x * 64, y * 64);
			else
				mlx_put_image_to_window(game.mlx, game.wlx, game.img.exit, x * 64, y * 64);
			x++;
		}
		y++;
	}
	
}