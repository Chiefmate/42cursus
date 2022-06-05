/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:54:06 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/05 18:04:16 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
 *	r == 2 or 3 during sorting
 */
void	new_sml_sort_a(t_stack *a, t_stack *b, int r)
{
	int	data[3];

	write(1, "smlsort start\n", 14);
	if (r == 2)
	{
		if (a->head->data > a->head->next->data)
			sa(a);
		return ;
		write(1, "smlsort 2\n", 10);
	}
	data[0] = a->head->data;
	data[1] = a->head->next->data;
	data[2] = a->head->next->next->data;
	if (data[0] < data[1] && data[1] < data[2])	// 123
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
	write(1, "smlsort end\n", 12);
	return ;
}