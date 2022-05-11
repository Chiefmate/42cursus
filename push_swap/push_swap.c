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

    a = create_stack();
    b = create_stack();

    push_top(a, 1);
    push_top(a, 1);
    push_top(a, 1);
    push_top(a, 1);
    push_top(b, 1);
    push_top(b, 1);
    push_top(b, 1);

    print_stack(a, b);

    destroy_stack(a);
    destroy_stack(b);
    return (0);
}