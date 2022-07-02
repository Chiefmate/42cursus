/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_sml4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:35:33 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/25 14:51:38 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sml_sort_four_case1(t_stack *a, t_stack *b)
{
	pa(a, b);
	sa(a);
}

void	sml_sort_four_case2(t_stack *a, t_stack *b)
{
	rra(a);
	pa(a, b);
	ra(a);
	ra(a);
}

void	sml_sort_four_case3(t_stack *a, t_stack *b)
{
	pa(a, b);
	ra(a);
}

void	pa_three_times(t_stack *a, t_stack *b)
{
	pa(a, b);
	pa(a, b);
	pa(a, b);
}
