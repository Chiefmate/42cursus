/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:01:09 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/27 15:59:19 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* used in parser.c */
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
