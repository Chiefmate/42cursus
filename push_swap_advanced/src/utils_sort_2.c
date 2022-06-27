/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 00:32:50 by marvin            #+#    #+#             */
/*   Updated: 2022/06/28 00:32:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* 남은 아이들이 전부 pivot[2]보다 큰 얘들만 있다면 넘기지 않아도 됨 */
int	is_every_left_num2(t_stack *a, int d, int pivot[])
{
	int		i;
	t_node	*curr;

	if (d <= 0)
		return (1);
	curr = a->head;
	i = 0;
	while (++i <= d && curr)
	{
		if (curr->data < pivot[2])
			return (0);
		curr = curr->next;
	}
	return (1);
}