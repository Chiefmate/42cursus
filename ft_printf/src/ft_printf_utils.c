/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:52:48 by hyunhole          #+#    #+#             */
/*   Updated: 2022/02/19 20:55:40 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*s;
	size_t			k;

	s = (unsigned char *)b;
	k = 0;
	while (k < n)
	{
		s[k] = c;
		k++;
	}
	return (b);
}

int	ft_putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(int fd, char *s)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (s[i])
	{
		ret += ft_putchar_fd(fd, s[i]);
		i++;
	}
	return (ret);
}

int	ft_putnbr_fd(int fd, int num)
{
	long long	temp;
	char		prt[30];
	int			idx;

	idx = 0;
	ft_memset(prt, 0, 30);
	temp = num;
	if (num < 0)
		temp = -num;
	if (!num)
		return (ft_putchar_fd(fd, '0'));
	while (temp)
	{
		prt[idx++] = temp % 10 + '0';
		temp /= 10;
	}
	if (num < 0)
		prt[idx++] = '-';
	temp = idx;
	while (--idx >= 0)
		write(fd, &prt[idx], 1);
	return (temp);
}

int	ft_puthex_fd(int fd, long long num, char c)
{
	long long	temp;
	char		prt[30];
	int			idx;
	char		*sml;
	char		*big;

	sml = "0123456789abcdef";
	big = "0123456789ABCDEF";
	idx = 0;
	ft_memset(prt, 0, 30);
	temp = num;
	if (!num)
		return (ft_putchar_fd(fd, '0'));
	while (temp)
	{
		if (c == 'X')
			prt[idx] = big[temp % 16];
		else
			prt[idx] = sml[temp % 16];
		idx++;
		temp /= 16;
	}
	if (num < 0)
		prt[idx++] = '-';
	temp = idx;
	while (--idx >= 0)
		write(fd, &prt[idx], 1);
	return (temp);
}
