/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:05:52 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/04 15:59:32 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *  Internal Instructions for stack rules
 */

#include "../include/push_swap.h"

/*
 *  ft_pop the element from the bottom and assign the popped value to *data_out
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
        ft_pop(s, &num);
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
int     ft_swap(t_stack *s)
{
    int     temp1;
    int     temp2;

    if (s->count <= 1)
        return (0);
    ft_pop(s, &temp1);
    ft_pop(s, &temp2);
    push_top(s, temp1);
    push_top(s, temp2);
    return (0);
}

/*
 *  Put the top element to dst from src and delete the element in src
 *  Do nothing if src is empty
 *  return 0
 */
int     ft_push(t_stack *dst, t_stack *src)
{
    int temp;

    if (src->count <= 0)
        return (0);
    ft_pop(src, &temp);
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
    ft_pop(s, &temp);
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

