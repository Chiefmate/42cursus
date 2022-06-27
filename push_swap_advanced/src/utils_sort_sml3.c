/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_sml3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:55:35 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/25 14:07:38 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	new_smlsort_case132(t_stack *a, t_stack *b)
{
	pb(a, b);
	sa(a);
	pa(a, b);
}

void	new_smlsort_case213(t_stack *a)
{
	sa(a);
}

void	new_smlsort_case231(t_stack *a, t_stack *b)
{
	pb(a, b);
	sa(a);
	pa(a, b);
	sa(a);
}

void	new_smlsort_case312(t_stack *a, t_stack *b)
{
	sa(a);
	pb(a, b);
	sa(a);
	pa(a, b);
}

void	new_smlsort_case321(t_stack *a, t_stack *b)
{
	sa(a);
	pb(a, b);
	sa(a);
	pa(a, b);
	sa(a);
}
