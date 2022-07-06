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
# include <stdio.h>
# include <fcntl.h>

/* get_next_line */
# include <limits.h>
# ifndef OPEN_MAX
	#define OPEN_MAX			32
# endif
# define BUFFER_SIZE	10

/* img_size */
# define IMG_SIZE				32

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17
# define KEY_ESC				53
# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2

typedef	struct	s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef	struct	s_map
{
	int		width;
	int		height;
	int		num_collect;
	char	*info;
}				t_map;

typedef	struct	s_imgstore
{
	void	*empty;
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit;
}				t_imgstore;

typedef	struct	s_game
{
	void		*mlx;
	void		*wlx;
	t_map		*l_map;
	int			walk_cnt;
	int			collected_cnt;
	t_imgstore	img;
}				t_game;

/* so_long.c */
int		ft_exit_error(char *m);
int		exit_game(t_game *game);

/* map_to_img */
t_game	*make_game(t_map *map);
void	map_to_img(t_game game);

/* key_event */
void	end_game(t_game *g);
void	clear_game(t_game *g);
int		press_key(int key, t_game *game);

void	move_w(t_game *g);
void	move_a(t_game *g);
void	move_s(t_game *g);
void	move_d(t_game *g);

/* load_map */
void	load_map(char *filename, t_map *map);

/* get_next_line */
char	*get_next_line(int fd);
size_t	ft_strnlen(char *str, size_t n);

/* check_map */
void	check_map(t_map *map);

#endif