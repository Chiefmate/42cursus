/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:59:36 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/27 17:26:05 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc <= 1)
		return (0);
	a = create_stack();
	b = create_stack();
	parse_input(a, argc, argv);
	if (a->count <= 5)
		sml_sort_a(a, b, a->count);
	else
		a_to_b(a, b, a->count);

	print_stack(a, b);
	
	destroy_stack(a);
	destroy_stack(b);
	return (0);
}
