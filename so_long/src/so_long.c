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
	void	*mlx_ptr;
	void	*win_ptr;
	t_coord	param;
	t_map	map;

	if (argc <= 1 || argc > 2)
		return (0);
	load_map(argv[1], &map);
	init_coord(&param);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "so_long");
	mlx_hook(win_ptr, X_EVENT_KEY_RELEASE, 0, get_pressed_key, &param);
	mlx_loop(mlx_ptr);
	return (0);
}
