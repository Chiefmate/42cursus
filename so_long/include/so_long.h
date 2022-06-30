/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:24:24 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/27 21:01:18 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../minilibx_opengl_20191021/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h>			/* must be deleted */

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define KEY_ESC				53
# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2

/* OPEN_MAX */
#include <limits.h>
/* 매크로 선언 여기서 해도 되는지 norm 확인 필요 */
#define BUFFER_SIZE	10


typedef	struct	s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef	struct	s_map
{
	int		width;
	int		height;
	char	*info;
}				t_map;

void	init_coord(t_coord *param);
int		get_pressed_key(int key, t_coord *param);
void	load_map(char *filename, t_map *map);
char	*get_next_line(int fd);
size_t	ft_strnlen(char *str, size_t n);

#endif
