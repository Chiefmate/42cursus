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
	if (!s)
		return (ft_putstr_fd(fd, "(null)"));
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
	char		prt[22];
	int			idx;

	idx = 0;
	ft_memset(prt, 0, 22);
	if (num < 0)
		temp = (long long)-num;
	else
		temp = num;
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

int	ft_putunbr_fd(int fd, unsigned int num)
{
	long long	temp;
	char		prt[22];
	int			idx;

	idx = 0;
	ft_memset(prt, 0, 22);
	if (num < 0)
		temp = -num;
	else
		temp = num;
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