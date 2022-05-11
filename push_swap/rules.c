/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:05:52 by hyunhole          #+#    #+#             */
/*   Updated: 2022/05/11 19:05:52 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *  Instructions for stacks
 */

#include "push_swap.h"

int     swap(t_stack *a, t_stack *b)
{

}

int     push(t_stack *dst, t_stack *src)
{

}

int     rotate(t_stack *s)
{

}

int     rev_rotate(t_stack *s)
{

}

/*  internal use
 *  stack print function
 *  SHOULD BE DELETED WHEN SUBMITTING
 */
void    print_stack(t_stack *a, t_stack *b)
{
    int     count;
    t_node  *temp_a;
    t_node  *temp_b;
    int     num_a;
    int     num_b;

    count = a->count;
    if (count < b->count)
        count = b->count;
    temp_a = a->head;
    temp_b = b->head;
    for (int i = 0; i < count; i++)
    {
        if (!temp_a)
            num_a = ' ';
        else
        {
            num_a = temp_a->data + '0';
            temp_a = temp_a->next;
        }
        if (!temp_b)
            num_b = ' ';
        else
        {
            num_b = temp_b->data + '0';
            temp_b = temp_b->next;
        }
        printf("%c %c\n", num_a, num_b);
    }
    printf("- -\na b\n%d %d\n", a->count, b->count);
    
    printf("-------------------------\n");
    return ;
}