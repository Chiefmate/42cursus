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

#include "../include/push_swap.h"
#include <time.h>

int main(int argc, char *argv[])
{
    t_stack *a;
    t_stack *b;

    if (argc <= 1)
        return (0);
    // write(1, "create a\n", 9);
    a = create_stack();
    // write(1, "parse\n", 6);
    parse_input(a, argc, argv);

    // write(1, "create b\n", 9);
    b = create_stack();

    // write(1, "sort start\n", 11);
    print_stack(a, b);

    if (a->count <= 3)
        sml_sort_a(a, a->count);
    else
        a_to_b(a, b, a->count);
    print_stack(a, b);

    // write(1, "destroy stacks\n", 15);
    destroy_stack(a);
    destroy_stack(b);
    // write(1, "done\n", 5);
    return (0);
}