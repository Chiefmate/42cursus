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
    int     cnt;

    a = create_stack();
    b = create_stack();
    cnt = 0;
    if (parse_input(a, argc, argv, &cnt))
    {
        destroy_stack(a);
        destroy_stack(b);
        ft_error();
    }
    print_stack(a, b);

    a_to_b(a, b, cnt);

    print_stack(a, b);

    destroy_stack(a);
    destroy_stack(b);

    return (0);
}