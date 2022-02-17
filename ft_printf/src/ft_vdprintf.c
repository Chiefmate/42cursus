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
	ret += ft_putchar_fd(fd, 'k');
	ret += ft_putstr_fd(fd, "I'm king!\n", a);
	ret += ft_puthex_fd(fd, (long long)&a, a);
	ret += ft_putnbr_fd(fd, 12345, a);
	ret += ft_putnbr_fd(fd, -123, a);
	ret += ft_putnbr_fd(fd, 0, a);
	ret += ft_puthex_fd(fd, 255, a);
	printf("\nret: %d\n", ret);
	return (ret);
}