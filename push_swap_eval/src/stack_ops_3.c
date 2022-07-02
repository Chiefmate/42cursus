/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:25:40 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/25 15:15:23 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	p_f_b_exceptions(t_stack *s, int *data_out);

/*
 *  ft_pop the element from the bottom and assign the popped value to *data_out
 *  do nothing if s->count <= 0
 *  return  1   if successful
 *		  0   if empty
 */
int	pop_from_bot(t_stack *s, int *data_out)
{
	t_node	*temp;
	t_node	*pre_temp;

	if (s->head == NULL || s->count <= 1)
		return (p_f_b_exceptions(s, data_out));
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

static int	p_f_b_exceptions(t_stack *s, int *data_out)
{
	int	num;

	if (s->head == NULL)
		s->count = 0;
	if (!s->count)
		return (0);
	else if (s->count == 1)
	{
		ft_pop(s, &num);
		*data_out = num;
		return (1);
	}
	return (0);
}
