/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:14:04 by hyunhole          #+#    #+#             */
/*   Updated: 2022/03/04 15:30:56 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_process_longlong(int fd, unsigned long long value, char c)
{
	int	ret;

	ret = 0;
	if (c == 'p')
	{
		ret += ft_putstr_fd(fd, "0x");
		ret += ft_putadd_fd(fd, value);
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
		ret += ft_putunbr_fd(fd, value);
	else if (c == 'x')
		ret += ft_puthexsml_fd(fd, value);
	else if (c == 'X')
		ret += ft_puthexbig_fd(fd, value);
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
			else if (*fmt == 'c' || *fmt == 'd' || *fmt == 'i' || *fmt == 'u' \
			|| *fmt == 'x' || *fmt == 'X' )
				ret += ft_process_int(fd, va_arg(ap, unsigned int), *fmt);
			else if (*fmt == 's')
				ret += ft_putstr_fd(fd, va_arg(ap, char *));
			else if (*fmt == 'p')
				ret += ft_process_longlong(fd, \
						va_arg(ap, unsigned long long), *fmt);
			fmt++;
		}
		else
			ret += ft_putchar_fd(fd, *(fmt++));
	}
	va_end(ap);
	return (ret);
}
