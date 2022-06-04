/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_sml2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:45:39 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/04 16:27:22 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/push_swap.h"


void    smlsort_b_case312(t_stack *b)
{
    sb(b);
    rb(b);
}

void    smlsort_b_case231(t_stack *b)
{
    sb(b);
}

void    smlsort_b_case213(t_stack *b)
{
    rrb(b);
}

void    smlsort_b_case132(t_stack *b)
{
    rb(b);
}

void    smlsort_b_case123(t_stack *b)
{
    sb(b);
    rrb(b);
}
