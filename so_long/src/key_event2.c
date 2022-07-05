/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:35:21 by hyunhole          #+#    #+#             */
/*   Updated: 2022/07/05 19:35:21 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_game(t_game *g)
{
	g->walk_cnt++;
	printf("Clear! Walked %d steps", g->walk_cnt);
	exit(0);
}

void	move_w(t_map *m, t_game *g)
{
	int	i;

	i = -1;
	while (++i < ft_strlen(m->info))
	{
		if (m->info[i] == 'P')
			break ;
	}
	if (m->info[i - m->width] == 'E' && m->num_collect == g->collected_cnt)
		clear_game(g);
	if (m->info[i - m->width] == 'C')
		g->collected_cnt += 1;
	else if (m->info[i - m->width] != '1' && m->info[i - g->wid] != 'E')
	{
		m->info[i] = '0';
		m->info[i - m->width] = 'P';
		g->walk_cnt += 1;
		printf("%d\n", g->walk_cnt);
		map_to_img(*m, *g);
	}
}

void	move_a(t_map *m, t_game *g)
{
	int	i;

	i = -1;
	while (++i < ft_strlen(m->info))
	{
		if (m->info[i] == 'P')
			break ;
	}
	if (m->info[i - 1] == 'E' && m->num_collect == g->collected_cnt)
		clear_game(g);
	if (m->info[i - 1] == 'C')
		g->collected_cnt += 1;
	else if (m->info[i - 1] != '1' && m->info[i - 1] != 'E')
	{
		m->info[i] = '0';
		m->info[i - 1] = 'P';
		g->walk_cnt += 1;
		printf("%d\n", g->walk_cnt);
		map_to_img(*m, *g);
	}
}

void	move_s(t_map *m, t_game *g)
{
	int	i;

	i = -1;
	while (++i < ft_strlen(m->info))
	{
		if (m->info[i] == 'P')
			break ;
	}
	if (m->info[i + m->width] == 'E' && m->num_collect == g->collected_cnt)
		clear_game(g);
	if (m->info[i + m->width] == 'C')
		g->collected_cnt += 1;
	else if (m->info[i + m->width] != '1' && m->info[i + m->width] != 'E')
	{
		m->info[i] = '0';
		m->info[i + m->width] = 'P';
		g->walk_cnt += 1;
		printf("%d\n", g->walk_cnt);
		map_to_img(*m, *g);
	}
}

void	move_d(t_map *m, t_game *g)
{
	int	i;

	i = -1;
	while (++i < ft_strlen(m->info))
	{
		if (m->info[i] == 'P')
			break ;
	}
	if (m->info[i + 1] == 'E' && m->num_collect == g->collected_cnt)
		clear_game(g);
	if (m->info[i + 1] == 'C')
		g->collected_cnt += 1;
	else if (m->info[i + 1] != '1' && m->info[i + 1] != 'E')
	{
		m->info[i] = '0';
		m->info[i + 1] = 'P';
		g->walk_cnt += 1;
		printf("%d\n", g->walk_cnt);
		map_to_img(*m, *g);
	}
}
