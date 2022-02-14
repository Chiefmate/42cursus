/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:14:04 by hyunhole          #+#    #+#             */
/*   Updated: 2022/02/14 16:14:04 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	t_info	a;
	int		ret;

	ret = 0;
	ret += ft_putnbr_fd(fd, 1, a);
	ret += ft_putnbr_fd(fd, -123, a);
	ret += ft_putnbr_fd(fd, 321, a);
	ret += ft_putnbr_fd(fd, 0, a);
	printf("\nret: %d\n", ret);
	return (ret);
}