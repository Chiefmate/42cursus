/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:35:21 by hyunhole          #+#    #+#             */
/*   Updated: 2022/07/06 10:58:56 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_w(t_game *g)
{
	int		i;
	t_map	*m = g->l_map;

	m = g->l_map;
	i = -1;
	while (++i < (int)ft_strlen(m->info))
	{
		if (m->info[i] == 'P')
			break ;
	}
	if (m->info[i - m->width] == 'E' && m->num_collect == g->collected_cnt)
		clear_game(g);
	if (m->info[i - m->width] == 'C')
		g->collected_cnt += 1;
	if (m->info[i - m->width] != '1' && m->info[i - m->width] != 'E')
	{
		m->info[i] = '0';
		m->info[i - m->width] = 'P';
		g->walk_cnt += 1;
		printf("%d\n", g->walk_cnt);
		map_to_img(*g);
	}
}

void	move_a(t_game *g)
{
	int	i;
	t_map	*m = g->l_map;

	m = g->l_map;
	i = -1;
	while (++i < (int)ft_strlen(m->info))
	{
		if (m->info[i] == 'P')
			break ;
	}
	if (m->info[i - 1] == 'E' && m->num_collect == g->collected_cnt)
		clear_game(g);
	if (m->info[i - 1] == 'C')
		g->collected_cnt += 1;
	if (m->info[i - 1] != '1' && m->info[i - 1] != 'E')
	{
		m->info[i] = '0';
		m->info[i - 1] = 'P';
		g->walk_cnt += 1;
		printf("%d\n", g->walk_cnt);
		map_to_img(*g);
	}
}

void	move_s(t_game *g)
{
	int	i;
	t_map	*m = g->l_map;

	m = g->l_map;
	i = -1;
	while (++i < (int)ft_strlen(m->info))
	{
		if (m->info[i] == 'P')
			break ;
	}
	if (m->info[i + m->width] == 'E' && m->num_collect == g->collected_cnt)
		clear_game(g);
	if (m->info[i + m->width] == 'C')
		g->collected_cnt += 1;
	if (m->info[i + m->width] != '1' && m->info[i + m->width] != 'E')
	{
		m->info[i] = '0';
		m->info[i + m->width] = 'P';
		g->walk_cnt += 1;
		printf("%d\n", g->walk_cnt);
		map_to_img(*g);
	}
}

void	move_d(t_game *g)
{
	int	i;
	t_map	*m = g->l_map;

	m = g->l_map;
	i = -1;
	while (++i < (int)ft_strlen(m->info))
	{
		if (m->info[i] == 'P')
			break ;
	}
	if (m->info[i + 1] == 'E' && m->num_collect == g->collected_cnt)
		clear_game(g);
	if (m->info[i + 1] == 'C')
		g->collected_cnt += 1;
	if (m->info[i + 1] != '1' && m->info[i + 1] != 'E')
	{
		m->info[i] = '0';
		m->info[i + 1] = 'P';
		g->walk_cnt += 1;
		printf("%d\n", g->walk_cnt);
		map_to_img(*g);
	}
}