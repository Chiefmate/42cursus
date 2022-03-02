/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:40:54 by hyunhole          #+#    #+#             */
/*   Updated: 2022/02/25 01:02:29 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

unsigned long long	ft_puthexsml_fd(int fd, unsigned long long num)
{
	unsigned long long	temp;
	char				prt[23];
	int					idx;
	char				*sml;

	sml = "0123456789abcdef";
	idx = 0;
	ft_memset(prt, 0, 22);
	temp = num;
	if (!num)
		return (ft_putchar_fd(fd, '0'));
	while (temp)
	{
		prt[idx++] = sml[temp % 16];
		temp /= 16;
	}
	if (num < 0)
		prt[idx++] = '-';
	temp = idx;
	while (--idx >= 0)
		write(fd, &prt[idx], 1);
	return (temp);
}

unsigned long long	ft_puthexbig_fd(int fd, unsigned long long num)
{
	unsigned long long	temp;
	char				prt[23];
	int					idx;
	char				*big;

	big = "0123456789ABCDEF";
	idx = 0;
	ft_memset(prt, 0, 22);
	temp = num;
	if (!num)
		return (ft_putchar_fd(fd, '0'));
	while (temp)
	{
		prt[idx++] = big[temp % 16];
		temp /= 16;
	}
	if (num < 0)
		prt[idx++] = '-';
	temp = idx;
	while (--idx >= 0)
		write(fd, &prt[idx], 1);
	return (temp);
}
