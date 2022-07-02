/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_sml5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:39:47 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/25 14:43:46 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sml_sort_five_case1(t_stack *a, t_stack *b)
{
	pa(a, b);
	sa(a);
}

void	sml_sort_five_case2(t_stack *a, t_stack *b)
{
	ra(a);
	pa(a, b);
	sa(a);
	rra(a);
}

void	sml_sort_five_case3(t_stack *a, t_stack *b)
{
	rra(a);
	pa(a, b);
	ra(a);
	ra(a);
}

void	sml_sort_five_case4(t_stack *a, t_stack *b)
{
	pa(a, b);
	ra(a);
}
