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

int main(void)
{
    t_stack *a;
    t_stack *b;

    a = create_stack();
    b = create_stack();
    push_top(a, -3);
    push_top(a, 7);
    push_top(a, -9);
    print_stack(a, b);

    a_to_b(a, b, 6);
    print_stack(a, b);
    destroy_stack(a);
    destroy_stack(b);
    return (0);
}
