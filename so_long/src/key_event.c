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

int	get_pressed_key(int key, t_coord *param)
{
	if (key == KEY_W)
		param->y += 1;
	else if (key == KEY_A)
		param->x -= 1;
	else if (key == KEY_S)
		param->y -= 1;
	else if (key == KEY_D)
		param->x += 1;
	else if (key == KEY_ESC)
		exit(0);
	printf("x: %d, y: %d\n", param->x, param->y);
	return (0);
}
