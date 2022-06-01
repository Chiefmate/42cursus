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

/*	avl tree에 저장
 */
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

void	intarr_sort(int arr[], int n)
{
	
}