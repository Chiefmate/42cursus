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
 *  Internal Instructions for stacks
 */

#include "push_swap.h"

/*
 *  pop the element from the bottom and assign the popped value to *data_out
 *  do nothing if s->count <= 0
 *  return  1   if successful
 *          0   if empty
 */
int     pop_from_bot(t_stack *s, int *data_out)
{
    t_node  *temp;
    t_node  *pre_temp;
    int     num;

    if (!s->count)
        return (0);
    else if (s->count == 1)
    {
        pop(s, &num);
        *data_out = num;
        return (1);        
    }
    pre_temp = NULL;
    temp = s->head;
    while (temp->next)
    {
        pre_temp = temp;
        temp = temp->next;
    }
    pre_temp->next = NULL;
    *data_out = temp->data;
    temp->data = 0;
    temp->next = NULL;
    free(temp);
    s->count--;
    return (1);
}

/*
 *  Swaps the first and the second elements of the stack
 *  Do nothing if s->count <= 1
 *  return 0
 */
int     swap(t_stack *s)
{
    int     temp1;
    int     temp2;

    if (s->count <= 1)
        return (0);
    pop(s, &temp1);
    pop(s, &temp2);
    push_top(s, temp1);
    push_top(s, temp2);
    return (0);
}

/*
 *  Put the top element to dst from src and delete the element in src
 *  Do nothing if src is empty
 *  return 0
 */
int     push(t_stack *dst, t_stack *src)
{
    int temp;

    if (src->count <= 0)
        return (0);
    pop(src, &temp);
    push_top(dst, temp);
    return (0);
}

/*
 *  Shift up all elements of stack s by 1.
 *  The first element becomes the last one.
 *  Do nothing if s->count <= 1
 *  return 0
 */
int     rotate(t_stack *s)
{
    int temp;

    if (s->count <= 1)
        return (0);
    pop(s, &temp);
    push_bottom(s, temp);
    return (0);
}

/*
 *  Shift down all elements of stack a by 1.
 *  The last element becomes the first one.
 *  Do nothing if s->count <= 1
 *  return 0
 */
int     rev_rotate(t_stack *s)
{
    int temp;

    if (s->count <= 1)
        return (0);
    pop_from_bot(s, &temp);
    push_top(s, temp);
    return (0);
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
        if (!temp_a && !temp_b)
            printf(" \t \n");
        else if (!temp_a)
        {
            num_b = temp_b->data;
            temp_b = temp_b->next;
            printf(" \t%d\n", num_b);
        }
        else if (!temp_b)
        {
            num_a = temp_a->data;
            temp_a = temp_a->next;
            printf("%d\t \n", num_a);
        }
        else
        {
            num_a = temp_a->data;
            temp_a = temp_a->next;
            num_b = temp_b->data;
            temp_b = temp_b->next;
            printf("%d\t%d\n", num_a, num_b);
        }
    }
    printf("-\t-\na\tb\n%d\t%d\n", a->count, b->count);
    
    printf("-------------------------\n");
    return ;
}