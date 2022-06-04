/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 12:10:06 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/04 15:01:29 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*  select left pivot and right pivot in stack a within r elements 
 *  assign selected pivots in array pivot: pivot[0] = lp, pivot[1] = rp
 */
void    select_pivots(t_stack *a, int r, int pivot[])
{
	t_node	*temp;
	int		arr[r];
	int		idx;

	idx = 0;
	temp = a->head;
	while (temp)
	{
		arr[idx] = temp->data;
		temp = temp->next;
		idx++;
	}
	intarr_sort(arr, 0, idx - 1);
	pivot[0] = arr[r / 3];
	pivot[1] = arr[2 * r / 3];
	return ;
}

/*	quicksort, in int array
 *	begin = leftmost index, end = rightmost index
 */

void	intarr_sort(int arr[], int begin, int end)
{
	int	pivotidx;

	if (begin < end)
	{
		pivotidx = partition(arr, begin, end);
		intarr_sort(arr, begin, pivotidx);
		intarr_sort(arr, pivotidx + 1, end);
	}
	return ;
}

int	partition(int arr[], int begin, int end)
{
	int	pivotidx;
	int	storeidx;
	int	i;
	int	temp;

	pivotidx = end;
	storeidx = begin - 1;
	i = begin;
	while (i < end)
	{
		if (arr[i] < arr[pivotidx])
		{
			temp = arr[i];
			arr[i] = arr[storeidx];
			arr[storeidx] = temp;
			storeidx++;
		}
		i++;
	}
	temp = arr[storeidx + 1];
	arr[storeidx + 1] = arr[pivotidx];
	arr[pivotidx] = temp;
	return (storeidx + 1);
}
