/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_sml2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:45:39 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/05 18:00:07 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/push_swap.h"


void    smlsort_b_case312(t_stack *a, t_stack *b)
{
    pa(a, b);
    sb(b);
    pa(a, b);
    pa(a, b);
}

void    smlsort_b_case231(t_stack *a, t_stack *b)
{
    sb(b);
    pa(a, b);
    pa(a, b);
    pa(a, b);
}

void    smlsort_b_case213(t_stack *a, t_stack *b)
{
    pa(a, b);
    sb(b);
    pa(a, b);
    sa(a);
    pa(a, b);
}

void    smlsort_b_case132(t_stack *a, t_stack *b)
{
    sb(b);
    pa(a, b);
    sb(b);
    pa(a, b);
    pa(a, b);
}

void    smlsort_b_case123(t_stack *a, t_stack *b)
{
    pa(a, b);
    sb(b);
    pa(a, b);
    sa(a);
    pa(a, b);
    sa(a);
}
