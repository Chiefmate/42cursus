/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:00:05 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/25 14:30:43 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *  Internal Functions for stacks
 */

#include "../include/push_swap.h"

/*
 *  push data on the top of the stack
 *  return  1   if successful
 *		  0   if overflow
 */
int	push_top(t_stack *s, int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->data = data;
	if (!s->count)
	{
		new_node->next = NULL;
		s->head = new_node;
	}
	else
	{
		new_node->next = s->head;
		s->head = new_node;
	}
	s->count++;
	return (1);
}

/*
 *  push data on the bottom of the stack
 *  return  1   if successful
 *		  0   if overflow
 */
int	push_bottom(t_stack *s, int data)
{
	t_node	*new_node;
	t_node	*temp;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->data = data;
	new_node->next = NULL;
	if (s->head == NULL || !s->count)
	{
		s->head = new_node;
	}
	else
	{
		temp = s->head;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = new_node;
	}
	s->count++;
	return (1);
}

/*
 *  pop the element and assign the popped value to *data_out
 *  return  1   if successful
 *		  0   if empty
 */
int	ft_pop(t_stack *s, int *data_out)
{
	t_node	*temp;

	if (s->head == NULL)
		s->count = 0;
	if (!s->count)
		return (0);
	temp = s->head;
	s->head = temp->next;
	*data_out = temp->data;
	temp->data = 0;
	temp->next = NULL;
	free(temp);
	s->count--;
	return (1);
}

/*  return  newly allocated t_stack ptr if successful
 *		  0                           if overflow
 */

t_stack	*create_stack(void)
{
	t_stack	*ret;

	ret = (t_stack *)malloc(sizeof(t_stack));
	if (!ret)
		return (NULL);
	ret->count = 0;
	ret->head = NULL;
	return (ret);
}

void	destroy_stack(t_stack *s)
{
	int	val;

	while (s->count > 0)
	{
		ft_pop(s, &val);
	}
	free(s);
	return ;
}
