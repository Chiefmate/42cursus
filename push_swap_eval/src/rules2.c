/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:02:36 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/25 14:59:34 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *  External Interface Instructions for stacks
 *	sa, sb, ss, pa, pb,
 *	ra, rb, rr, rra, rrb,
 *	rrr
 */

#include "../include/push_swap.h"

void	ra(t_stack *a)
{
	rotate(a);
	write(1, "ra\n", 3);
	return ;
}

void	rb(t_stack *b)
{
	rotate(b);
	write(1, "rb\n", 3);
	return ;
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	return ;
}

void	rra(t_stack *a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
	return ;
}

void	rrb(t_stack *b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
	return ;
}
