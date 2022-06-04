/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_sml1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:38:28 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/04 17:24:37 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


void    smlsort_case132(t_stack *a)
{
    sa(a);
    ra(a);
}

void    smlsort_case213(t_stack *a)
{
    sa(a);
}

void    smlsort_case231(t_stack *a)
{
    rra(a);
}

void    smlsort_case312(t_stack *a)
{
    ra(a);
}

void    smlsort_case321(t_stack *a)
{
    sa(a);
    rra(a);
}