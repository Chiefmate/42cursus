/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 20:40:26 by hyunhole          #+#    #+#             */
/*   Updated: 2022/05/25 20:40:26 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/***
void	A_to_B(t_stack *a, t_stack *b, int r)
{
	int	lp;
	int	rp;

	lp = select_lp(t_stack *a, r);
	rp = select_rp(t_stack *a, r);
}

void	B_to_A(t_stack *a, t_stack *b, int r)
{

}

***/

/*	avl tree에 저장
 */
/****
int	select_lp(t_stack *s, int r)
{
	int	*arr;
	int	i;

	arr = (int *)malloc((r + 1) * sizeof(int));
	if (!arr)
		return (0);
	i = -1;
	while (++i <= r)
		arr[i] = 0;
	
	
}

int	select_rp(t_stack *s, int r)
{
	
}
***/

void	intarr_sort(int arr[], int begin, int end)
{
	int	pivotidx;

	if (begin < end)
	{
		pivotidx = partition(arr, begin, end);
		intarr_sort(arr, begin, pivotidx);
		intarr_sort(arr, pivotidx + 1, end);
	}
}

int	partition(int arr[], int begin, int end)
{
	int	pivotidx;
	int	partidx;
	int	i;
	int	temp;

	pivotidx = end;
	partidx = begin - 1;
	i = begin;
	while (i < end)
	{
		if (arr[i] < arr[pivotidx])
		{
			temp = arr[i];
			arr[i] = arr[partidx];
			arr[partidx] = temp;
			partidx++;
		}
		i++;
	}
	temp = arr[partidx + 1];
	arr[partidx + 1] = arr[pivotidx];
	arr[pivotidx] = temp;
	return (partidx + 1);
}