/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:40:54 by hyunhole          #+#    #+#             */
/*   Updated: 2022/03/04 15:30:43 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

unsigned int	ft_puthexsml_fd(int fd, unsigned int num)
{
	unsigned int	temp;
	char			prt[23];
	int				idx;
	char			*sml;

	sml = "0123456789abcdef";
	idx = 0;
	ft_memset(prt, 0, 23);
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

unsigned int	ft_puthexbig_fd(int fd, unsigned int num)
{
	unsigned int	temp;
	char			prt[23];
	int				idx;
	char			*big;

	big = "0123456789ABCDEF";
	idx = 0;
	ft_memset(prt, 0, 23);
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

unsigned long long	ft_putadd_fd(int fd, unsigned long long num)
{
	unsigned long long	temp;
	char				prt[23];
	int					idx;
	char				*sml;

	sml = "0123456789abcdef";
	idx = 0;
	ft_memset(prt, 0, 23);
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