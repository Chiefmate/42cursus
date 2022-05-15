/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:59:36 by hyunhole          #+#    #+#             */
/*   Updated: 2022/05/11 18:59:36 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
    t_stack *a;
    t_stack *b;
    int     tempint;

    a = create_stack();
    b = create_stack();


    push_top(a, 1);
    push_top(a, 5);
    push_top(a, 4);
    push_top(a, 7);
    push_top(a, 9);
    print_stack(a, b);

    if (a->count <= 3)
        sml_sort(a, b, a->count);
    else
        dqsort(a, b, a->count);
    print_stack(a, b);

    destroy_stack(a);
    destroy_stack(b);
    return (0);
}