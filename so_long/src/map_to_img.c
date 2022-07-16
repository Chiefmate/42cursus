/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:07:51 by hyunhole          #+#    #+#             */
/*   Updated: 2022/07/06 11:24:10 by hyunhole         ###   ########.fr       */
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
	ret->wlx = mlx_new_window(ret->mlx, map->width * IS, \
			map->height * IS, "so_long");
	ret->l_map = map;
	ret->walk_cnt = 0;
	ret->col_cnt = 0;
	(ret->img).empt = mlx_xpm_file_to_image(ret->mlx, \
			"./asset/empty.xpm", &img_width, &img_height);
	(ret->img).wall = mlx_xpm_file_to_image(ret->mlx, \
			"./asset/wall.xpm", &img_width, &img_height);
	(ret->img).play = mlx_xpm_file_to_image(ret->mlx, \
			"./asset/player.xpm", &img_width, &img_height);
	(ret->img).c = mlx_xpm_file_to_image(ret->mlx, \
			"./asset/collectible.xpm", &img_width, &img_height);
	(ret->img).exit = mlx_xpm_file_to_image(ret->mlx, \
			"./asset/exit.xpm", &img_width, &img_height);
	return (ret);
}

void	map_to_img(t_game g)
{
	int		x;
	int		y;

	y = -1;
	while (++y < (g.l_map)->height)
	{
		x = -1;
		while (++x < (g.l_map)->width)
		{
			if ((g.l_map)->info[y * (g.l_map)->width + x] == '0')
				mlx_put_image_to_window(g.mlx, \
						g.wlx, g.img.empt, x * IS, y * IS);
			else if ((g.l_map)->info[y * (g.l_map)->width + x] == '1')
				mlx_put_image_to_window(g.mlx, \
						g.wlx, g.img.wall, x * IS, y * IS);
			else if ((g.l_map)->info[y * (g.l_map)->width + x] == 'P')
				mlx_put_image_to_window(g.mlx, \
						g.wlx, g.img.play, x * IS, y * IS);
			else if ((g.l_map)->info[y * (g.l_map)->width + x] == 'C')
				mlx_put_image_to_window(g.mlx, g.wlx, g.img.c, x * IS, y * IS);
			else
				mlx_put_image_to_window(g.mlx, \
						g.wlx, g.img.exit, x * IS, y * IS);
		}
	}
}
