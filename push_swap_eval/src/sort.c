/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 20:40:26 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/25 15:30:06 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

static void	move_parts_atob(t_stack *a, t_stack *b, int pivot[], int num[]);
static void	move_parts_btoa(t_stack *a, t_stack *b, int pivot[], int num[]);

/*
 *	arr num: num_ra, num_rb, num_pb
 */
void	a_to_b(t_stack *a, t_stack *b, int r)
{
	int		pivot[2];
	int		num[3];

	if (r <= 3)
	{
		new_sml_sort_a(a, b, r);
		return ;
	}
	if (select_pivots(a, r, pivot))
		ft_error_stacks(a, b);
	num[0] = r;
	move_parts_atob(a, b, pivot, num);
	backrotate_ra_rb(a, b, num);
	a_to_b(a, b, num[0]);
	b_to_a(a, b, num[1]);
	b_to_a(a, b, num[2] - num[1]);
}

static void	move_parts_atob(t_stack *a, t_stack *b, int pivot[], int num[])
{
	int	r;
	int	i;
	int	temp;

	r = num[0];
	ft_memset(num, 0, sizeof(int) * 3);
	i = -1;
	while (++i < r)
	{
		temp = a->head->data;
		if (temp >= pivot[1])
		{
			ra(a);
			num[0]++;
			continue ;
		}
		pb(a, b);
		num[2]++;
		if (temp >= pivot[0])
		{
			rb(b);
			num[1]++;
		}
	}
}

/*
 *	arr num: num_ra, num_rb, num_pa
 */
void	b_to_a(t_stack *a, t_stack *b, int r)
{
	int		pivot[2];
	int		num[3];

	if (r <= 3)
	{
		sml_sort_btoa(a, b, r);
		return ;
	}
	if (select_pivots(b, r, pivot))
		ft_error_stacks(a, b);
	num[0] = r;
	move_parts_btoa(a, b, pivot, num);
	a_to_b(a, b, num[2] - num[0]);
	backrotate_ra_rb(a, b, num);
	a_to_b(a, b, num[0]);
	b_to_a(a, b, num[1]);
}

static void	move_parts_btoa(t_stack *a, t_stack *b, int pivot[], int num[])
{
	int	r;
	int	i;
	int	temp;

	r = num[0];
	ft_memset(num, 0, sizeof(int) * 3);
	i = -1;
	while (++i < r)
	{
		temp = b->head->data;
		if (temp < pivot[0])
		{
			rb(b);
			num[1]++;
			continue ;
		}
		pa(a, b);
		num[2]++;
		if (temp < pivot[1])
		{
			ra(a);
			num[0]++;
		}
	}
}
