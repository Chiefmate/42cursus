/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:02:29 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/25 14:59:30 by hyunhole         ###   ########.fr       */
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
	ft_swap(a);
	write(1, "sa\n", 3);
	return ;
}

void	sb(t_stack *b)
{
	ft_swap(b);
	write(1, "sb\n", 3);
	return ;
}

void	ss(t_stack *a, t_stack *b)
{
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
	return ;
}

void	pa(t_stack *a, t_stack *b)
{
	ft_push(a, b);
	write(1, "pa\n", 3);
	return ;
}

void	pb(t_stack *a, t_stack *b)
{
	ft_push(b, a);
	write(1, "pb\n", 3);
	return ;
}
