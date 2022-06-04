/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:47:00 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/04 12:03:13 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *  External Interface Instructions for stacks
 *	sa, sb, ss, pa, pb,
 *	ra, rb, rr, rra, rrb,
 *	rrr
 */

#include "../include/push_swap.h"

void	sa(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
	return ;
}

void	sb(t_stack *b)
{
	swap(b);
	write(1, "sb\n", 3);
	return ;
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	return ;
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pa\n", 3);
	return ;
}

void	pb(t_stack *a, t_stack *b)
{
	push(b, a);
	write(1, "pb\n", 3);
	return ;
}