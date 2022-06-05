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

    a = create_stack();
    parse_input(a, argc, argv);

    b = create_stack();

    print_stack(a, b);

    a_to_b(a, b, a->count);

    print_stack(a, b);

    destroy_stack(a);
    destroy_stack(b);

    return (0);
}