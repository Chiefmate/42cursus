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

#include "../include/ft_printf.h"

int ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	int		ret;
	size_t	i;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			if (fmt[++i] == '%')
				ret += ft_putchar_fd(fd, fmt[i]);
			else if (fmt[i] == 'c')
				ret += ft_putchar_fd(fd, (char)va_arg(ap, int));
			else if (fmt[i] == 's')
				ret += ft_putstr_fd(fd, va_arg(ap, char *));
			else if (fmt[i] == 'p')
			{
				ret += ft_putstr_fd(fd, "0x");
				ret += ft_puthex_fd(fd, va_arg(ap, long long), 'x');
			}
			else if (fmt[i] == 'd' || fmt[i] == 'i')
				ret += ft_putnbr_fd(fd, va_arg(ap, int));
			else if (fmt[i] == 'u')
				ret += ft_putnbr_fd(fd, va_arg(ap, unsigned int));
			else if (fmt[i] == 'x')
				ret += ft_puthex_fd(fd, va_arg(ap, long long), 'x');
			else if (fmt[i] == 'X')
				ret += ft_puthex_fd(fd, va_arg(ap, long long), 'X');
			i++;
		}
		else
			ret += ft_putchar_fd(fd, fmt[i++]);
	}
	va_end(ap);
	return (ret);
}