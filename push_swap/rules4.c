/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:53:13 by hyunhole          #+#    #+#             */
/*   Updated: 2022/05/25 19:53:13 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *  External Interface Instructions for stacks
 *	sa, sb, ss, pa, pb,
 *	ra, rb, rr, rra, rrb,
 *	rrr
 */

#include "push_swap.h"

void	rrr(t_stack *a, t_stack *b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 3);
	return ;
}