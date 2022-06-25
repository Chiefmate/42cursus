/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:01:09 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/25 15:02:59 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error_with_clear(t_stack *a, char **splitarr)
{
	destroy_stack(a);
	write(2, "Error\n", 6);
	ft_destroy_split(splitarr);
	exit(1);
}

void	ft_error_stacks(t_stack *a, t_stack *b)
{
	destroy_stack(a);
	destroy_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
