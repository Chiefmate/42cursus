/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:43:32 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/25 15:13:35 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
 *	r == 2 or 3 when start
 *	this sortion use whole stack
 */
void	sml_sort_a(t_stack *a, t_stack *b, int r)
{
	if (r <= 1 || is_sorted(a, r))
		return ;
	if (r == 2)
	{
		if (a->head->data > a->head->next->data)
			sa(a);
		return ;
	}
	if (r == 4 || r == 5)
	{
		sml_sort_a_fourfive(a, b, r);
		return ;
	}
	else
		sml_sort_a_three(a);
	return ;
}

void	sml_sort_a_three(t_stack *a)
{
	int	data[3];

	data[0] = a->head->data;
	data[1] = a->head->next->data;
	data[2] = a->head->next->next->data;
	if (data[0] < data[1] && data[1] < data[2])
		return ;
	else if (data[0] < data[2] && data[2] < data[1])
		smlsort_case132(a);
	else if (data[1] < data[0] && data[0] < data[2])
		smlsort_case213(a);
	else if (data[2] < data[0] && data[0] < data[1])
		smlsort_case231(a);
	else if (data[1] < data[2] && data[2] < data[0])
		smlsort_case312(a);
	else
		smlsort_case321(a);
	return ;
}

void	sml_sort_a_fourfive(t_stack *a, t_stack *b, int r)
{
	int	data[4];

	if (r == 5)
		pb(a, b);
	pb(a, b);
	sml_sort_a_three(a);
	data[0] = a->head->data;
	data[1] = a->head->next->data;
	data[2] = a->head->next->next->data;
	if (b->head->data >= data[2])
		sml_sort_four_case3(a, b);
	else if (data[1] <= b->head->data && b->head->data < data[2])
		sml_sort_four_case2(a, b);
	else if (data[0] <= b->head->data && b->head->data < data[1])
		sml_sort_four_case1(a, b);
	else
		pa(a, b);
	if (r == 5)
		sml_sort_five_additional(a, b);
}

void	sml_sort_five_additional(t_stack *a, t_stack *b)
{
	int	data[4];

	data[0] = a->head->data;
	data[1] = a->head->next->data;
	data[2] = a->head->next->next->data;
	data[3] = a->head->next->next->next->data;
	if (b->head->data >= data[3])
		sml_sort_five_case4(a, b);
	else if (data[2] <= b->head->data && b->head->data < data[3])
		sml_sort_five_case3(a, b);
	else if (data[1] <= b->head->data && b->head->data < data[2])
		sml_sort_five_case2(a, b);
	else if (data[0] <= b->head->data && b->head->data < data[1])
		sml_sort_five_case1(a, b);
	else
		pa(a, b);
}
