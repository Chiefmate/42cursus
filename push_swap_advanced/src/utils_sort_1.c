/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 12:10:06 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/25 15:08:07 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap_int(int *a, int *b);

/*  select left pivot and right pivot in stack a within r elements 
 *  assign selected pivots in array pivot: pivot[0] = lp, pivot[1] = rp
 */
int	select_pivots(t_stack *a, int r, int pivot[])
{
	t_node	*temp;
	int		*arr;
	int		idx;

	arr = (int *)malloc(sizeof(int) * r);
	if (!arr)
		return (1);
	idx = 0;
	temp = a->head;
	while (temp && idx < r)
	{
		arr[idx] = temp->data;
		temp = temp->next;
		idx++;
	}
	intarr_sort(arr, 0, idx - 1);
	pivot[0] = arr[r / 3];
	pivot[1] = arr[(r / 3) * 2];
	free(arr);
	return (0);
}

/*	quicksort, in int array
 *	begin = leftmost index, end = rightmost index
 */

void	intarr_sort(int arr[], int begin, int end)
{
	int	i;
	int	j;
	int	pivot;
	int	temp;

	if (begin < end)
	{
		pivot = begin;
		i = begin;
		j = end;
		while (i < j)
		{
			while (arr[i] <= arr[pivot] && i < end)
				i++;
			while (arr[j] > arr[pivot])
				j--;
			if (i < j)
				swap_int(arr + i, arr + j);
		}
		temp = arr[pivot];
		arr[pivot] = arr[j];
		arr[j] = temp;
		intarr_sort(arr, begin, j - 1);
		intarr_sort(arr, j + 1, end);
	}
}

static void	swap_int(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
	return ;
}

int	is_sorted(t_stack *a, int r)
{
	int		temp;
	int		i;
	t_node	*curr;

	if (!a)
		return (1);
	curr = a->head;
	if (curr)
		temp = curr->data;
	i = 1;
	while (i < r && curr)
	{
		if (temp > curr->data)
			return (0);
		temp = curr->data;
		curr = curr->next;
	}
	return (1);
}

int	is_sorted_rev(t_stack *b, int r)
{
	int		temp;
	int		i;
	t_node	*curr;

	if (!b)
		return (1);
	curr = b->head;
	if (curr)
		temp = curr->data;
	i = 1;
	while (i < r && curr)
	{
		if (temp < curr->data)
			return (0);
		temp = curr->data;
		curr = curr->next;
	}
	return (1);
}
