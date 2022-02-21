/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:58:33 by hyunhole          #+#    #+#             */
/*   Updated: 2022/02/19 19:58:33 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"

int main(void)
{
	int	n;

	n = 12345;
	ft_printf("wow!\n");
	ft_printf("kim%dchi%d\n", 12, -21);
	ft_printf("%c\n", 't');
	ft_printf("%s%%\n", "testing %s");
	ft_printf("%x...\n%X...\n", 2147000, 2147000);
	ft_printf("%p\n", &n);
	ft_printf("nullptr: %p\n", 0);
	ft_printf("nullstr: %s\n", 0);
	return (0);
}