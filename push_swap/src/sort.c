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
 *	arr num: num_ra, num_rb, num_pb
 */
void	a_to_b(t_stack *a, t_stack *b, int r)
{
	int		pivot[2];
	int		temp;
	int		i;
	int		num[3];

	#if DEBUG
	write(1, "a_to_b starts\n", 14);
	#endif

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
		#if DEBUG
		write(1, "loop assign temp\n", 17);
		#endif

		if (a->head == NULL)
			ft_error_stacks(a, b);
		temp = a->head->data;

		#if DEBUG
		write(1, "loop assigned temp\n", 19);
		#endif

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
		#if DEBUG
		write(1, "loop cycle end\n", 15);
		#endif
	}
	backrotate_ra_rb(a, b, num);
	a_to_b(a, b, num[0]);
	b_to_a(a, b, num[1]);
	b_to_a(a, b, num[2] - num[1]);
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
		#if DEBUG
		write(1, "loopb assign temp\n", 18);
		#endif

		if (b->head == NULL)
			ft_error_stacks(a, b);
		temp = b->head->data;

		#if DEBUG
		write(1, "loopb assigned temp\n", 20);
		#endif

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

		#if DEBUG
		write(1, "loopb cycle end\n", 16);
		#endif
	}
	a_to_b(a, b, num[2] - num[0]);
	backrotate_ra_rb(a, b, num);
	a_to_b(a, b, num[0]);
	b_to_a(a, b, num[1]);
}
