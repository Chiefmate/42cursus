/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:54:06 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/25 15:13:24 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	new_sml_sort_a_exception(t_stack *a, int r);
static void	sml_sort_btoa_exception(t_stack *a, t_stack *b, int r);

/*
 *	r == 2 or 3 during sorting
 *	this sortion does not interfere with the elements inside the stack
 */
void	new_sml_sort_a(t_stack *a, t_stack *b, int r)
{
	int	data[3];

	if (is_sorted(a, r))
		return ;
	if (r <= 2)
	{
		new_sml_sort_a_exception(a, r);
		return ;
	}
	data[0] = a->head->data;
	data[1] = a->head->next->data;
	data[2] = a->head->next->next->data;
	if (data[0] < data[1] && data[1] < data[2])
		return ;
	else if (data[0] < data[2] && data[2] < data[1])
		new_smlsort_case132(a, b);
	else if (data[1] < data[0] && data[0] < data[2])
		new_smlsort_case213(a);
	else if (data[2] < data[0] && data[0] < data[1])
		new_smlsort_case231(a, b);
	else if (data[1] < data[2] && data[2] < data[0])
		new_smlsort_case312(a, b);
	else
		new_smlsort_case321(a, b);
	return ;
}

static void	new_sml_sort_a_exception(t_stack *a, int r)
{
	if (r == 2)
	{
		if (a->head->data > a->head->next->data)
			sa(a);
	}
	return ;
}

/*	sort r elements in stack b,
 *	and push to stack a in order
 */
void	sml_sort_btoa(t_stack *a, t_stack *b, int r)
{
	int	data[3];

	if (is_sorted_rev(b, r) || r <= 2)
	{
		sml_sort_btoa_exception(a, b, r);
		return ;
	}
	data[0] = b->head->data;
	data[1] = b->head->next->data;
	data[2] = b->head->next->next->data;
	if (data[2] < data[1] && data[1] < data[0])
		pa_three_times(a, b);
	else if (data[0] < data[2] && data[2] < data[1])
		smlsort_b_case132(a, b);
	else if (data[1] < data[0] && data[0] < data[2])
		smlsort_b_case213(a, b);
	else if (data[2] < data[0] && data[0] < data[1])
		smlsort_b_case231(a, b);
	else if (data[1] < data[2] && data[2] < data[0])
		smlsort_b_case312(a, b);
	else
		smlsort_b_case123(a, b);
	return ;
}

static void	sml_sort_btoa_exception(t_stack *a, t_stack *b, int r)
{
	int	i;
	
	if (r <= 1 || is_sorted_rev(b, r))
	{
		i = -1;
		while (++i < r)
			pa(a, b);
	}
	else if (r == 2)
	{
		if (b->head->data < b->head->next->data)
			sb(b);
		pa(a, b);
		pa(a, b);
	}
	return ;
}

void	backrotate_ra_rb(t_stack *a, t_stack *b, int num[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < num[0] && j < num[1])
	{
		rrr(a, b);
		i++;
		j++;
	}
	while (i < num[0])
	{
		rra(a);
		i++;
	}
	while (j < num[1])
	{
		rrb(b);
		j++;
	}
	return ;
}
