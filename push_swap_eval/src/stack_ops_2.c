/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:02:20 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/25 14:23:51 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *  Internal Instructions for stack rules
 */

#include "../include/push_swap.h"

/*
 *  Swaps the first and the second elements of the stack
 *  Do nothing if s->count <= 1
 *  return 0
 */
int	ft_swap(t_stack *s)
{
	int	temp1;
	int	temp2;

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
int	ft_push(t_stack *dst, t_stack *src)
{
	int	temp;

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
int	rotate(t_stack *s)
{
	int	temp;

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
int	rev_rotate(t_stack *s)
{
	int	temp;

	if (s->count <= 1)
		return (0);
	pop_from_bot(s, &temp);
	push_top(s, temp);
	return (0);
}
