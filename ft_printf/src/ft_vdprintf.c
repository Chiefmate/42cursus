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
			else if (*fmt == 'c')
				ret += ft_putchar_fd(fd, (char)va_arg(ap, int));
			else if (*fmt == 's')
				ret += ft_putstr_fd(fd, va_arg(ap, char *));
			else if (*fmt == 'p')
			{
				ret += ft_putstr_fd(fd, "0x");
				ret += ft_puthex_fd(fd, va_arg(ap, long long), 'x');
			}
			else if (*fmt == 'd' || *fmt == 'i')
				ret += ft_putnbr_fd(fd, va_arg(ap, int));
			else if (*fmt == 'u')
				ret += ft_putnbr_fd(fd, va_arg(ap, unsigned int));
			else if (*fmt == 'x')
				ret += ft_puthexsml_fd(fd, va_arg(ap, long long));
			else if (*fmt == 'X')
				ret += ft_puthexbig_fd(fd, va_arg(ap, long long));
		}
		else
			ret += ft_putchar_fd(fd, *(fmt++));
	}
	va_end(ap);
	return (ret);
}
