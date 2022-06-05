/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 20:40:26 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/05 18:03:41 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

/*
 *	r == 2 or 3 when start
 */
void	sml_sort_a(t_stack *a, int r)
{
	int	data[3];

	if (r == 2)
	{
		if (a->head->data > a->head->next->data)
			sa(a);
		return ;
	}
	data[0] = a->head->data;
	data[1] = a->head->next->data;
	data[2] = a->head->next->next->data;
	if (data[0] < data[1] && data[1] < data[2])	// 123
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

/*
 *	arr num: num_ra, num_rb, num_pb
 */
void	a_to_b(t_stack *a, t_stack *b, int r)
{
	int		pivot[2];
	int		temp;
	int		i;
	int		num[3];

	if (r <= 1)
		return ;
	if (is_sorted(a, r))
		return ;
	if (r <= 3)
	{
		new_sml_sort_a(a, b, r);
		return ;
	}
	if (select_pivots(a, r, pivot))
		ft_error_stacks(a, b);
	ft_memset(num, 0, sizeof(int) * 3);
	i = -1;
	while (++i < r)
	{
		if (a->head == NULL)
			ft_error_stacks(a, b);
		temp = a->head->data;
		if (temp >= pivot[1])
		{
			ra(a);
			num[0]++;
		}
		else
		{
			pb(a, b);
			num[2]++;
			if (temp >= pivot[0])
			{
				rb(b);
				num[1]++;
			}
		}
	}
	backrotate_ra_rb(a, b, num);
	a_to_b(a, b, num[0]);
	b_to_a(a, b, num[1]);
	b_to_a(a, b, num[2] - num[1]);
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

/*	sort r elements in stack b,
 *	and push to stack a in order
 */
void	sml_sort_btoa(t_stack *a, t_stack *b, int r)
{
	int	data[3];

	if (r == 2)
	{
		if (b->head->data < b->head->next->data)
			sb(b);
		pa(a, b);
		pa(a, b);
		return ;
	}
	data[0] = b->head->data;
	data[1] = b->head->next->data;
	data[2] = b->head->next->next->data;
	if (data[2] < data[1] && data[1] < data[0])
	{
		pa(a, b);
		pa(a, b);
		pa(a, b);
	}
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

/*
 *	arr num: num_ra, num_rb, num_pa
 */
void	b_to_a(t_stack *a, t_stack *b, int r)
{
	int		pivot[2];
	int		temp;
	int		i;
	int		num[3];

	if (r <= 1)
	{
		pa(a, b);
		return ;
	}
	if (is_sorted_rev(b, r))
		return ;
	if (r <= 3)
	{
		sml_sort_btoa(a, b, r);
		return ;
	}
	if (select_pivots(b, r, pivot))
		ft_error_stacks(a, b);
	ft_memset(num, 0, sizeof(int) * 3);
	i = -1;
	while (++i < r)
	{
		if (b->head == NULL)
			ft_error_stacks(a, b);
		temp = b->head->data;
		if (temp < pivot[0])
		{
			rb(b);
			num[1]++;
		}
		else
		{
			pa(a, b);
			num[2]++;
			if (temp < pivot[1])
			{
				ra(a);
				num[0]++;
			}
		}
	}
	a_to_b(a, b, num[2] - num[0]);
	backrotate_ra_rb(a, b, num);
	a_to_b(a, b, num[0]);
	b_to_a(a, b, num[1]);
}
