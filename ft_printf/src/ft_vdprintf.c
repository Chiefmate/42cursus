/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:14:04 by hyunhole          #+#    #+#             */
/*   Updated: 2022/02/20 16:49:02 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_process_longlong(int fd, unsigned long long value, char c)
{
	int	ret;

	ret = 0;
	if (c == 'c')
		ret += ft_putchar_fd(fd, (char)value);
	else if (c == 'x')
		ret += ft_puthexsml_fd(fd, (long long)value);
	else if (c == 'X')
		ret += ft_puthexbig_fd(fd, (long long)value);
	else if (c == 'p')
	{
		ret += ft_putstr_fd(fd, "0x");
		ret += ft_puthex_fd(fd, (long long)value, 'x');
	}
	return (ret);
}

static int	ft_process_int(int fd, unsigned int value, char c)
{
	int	ret;

	ret = 0;
	if (c == 'c')
		ret += ft_putchar_fd(fd, (char)value);
	else if (c == 'd' || c == 'i')
		ret += ft_putnbr_fd(fd, (int)value);
	else if (c == 'u')
		ret += ft_putnbr_fd(fd, value);
	return (ret);
}

int	ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	int		ret;

	ret = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (*(++fmt) == '%')
				ret += ft_putchar_fd(fd, *fmt);
			else if (*fmt == 'c' || *fmt == 'd' || *fmt == 'i' || *fmt == 'u')
				ret += ft_process_int(fd, (unsigned int)va_arg(ap, int), *fmt);
			else if (*fmt == 's')
				ret += ft_putstr_fd(fd, va_arg(ap, char *));
			else if (*fmt == 'x' || *fmt == 'X' || *fmt == 'p')
				ret += ft_process_longlong(fd, (unsigned long long)va_arg(ap, long long), *fmt);
		}
		else
			ret += ft_putchar_fd(fd, *(fmt++));
	}
	va_end(ap);
	return (ret);
}
