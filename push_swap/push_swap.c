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
    push_top(a, 2);
    push_top(a, 3);
    push_top(a, 4);
    push_top(b, 1);
    push_top(b, 2);
    push_top(b, 13);
    print_stack(a, b);

    pop(b, &tempint);
    printf("tempint: %d\n", tempint);
    print_stack(a, b);

    swap(b);
    print_stack(a, b);

    push_bottom(b, 5);
    print_stack(a, b);

    rotate(b);
    print_stack(a, b);

    rev_rotate(a);
    print_stack(a, b);

    destroy_stack(a);
    destroy_stack(b);
    return (0);
}