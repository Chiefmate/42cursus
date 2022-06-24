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

#if DEBUG
    write(1, "create a\n", 9);
#endif
    a = create_stack();
    
#if DEBUG
    write(1, "create b\n", 9);
#endif
    b = create_stack();    

#if DEBUG
    write(1, "parse\n", 6);
#endif
    parse_input(a, argc, argv);



#if DEBUG
    write(1, "sort start\n", 11);
    print_stack(a, b);
#endif

    if (a->count <= 5)
        sml_sort_a(a, b, a->count);
    else
        a_to_b(a, b, a->count);

#if DEBUG
    print_stack(a, b);

<<<<<<< HEAD
    write(1, "destroy stacks\n", 15);
#endif

    destroy_stack(a);
    destroy_stack(b);

#if DEBUG
    write(1, "done\n", 5);
#endif

=======
    // write(1, "destroy stacks\n", 15);
    destroy_stack(a);
    destroy_stack(b);
    // write(1, "done\n", 5);
>>>>>>> 52cd54141b2dd4862879644c8b58099f352417ac
    return (0);
}