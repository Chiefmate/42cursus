/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:30:52 by hyunhole          #+#    #+#             */
/*   Updated: 2022/02/12 12:30:52 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_putstr_fd(int fd, char *s, t_info info)
{
	int	ret;
	int	i;

	i = 0;
	while (s[i] && i < info.precision)
	{
		ret += ft_putchar_fd(fd, s[i]);
		i++;
	}
	return (ret);
}

int	ft_putnbr_fd(int fd, int num, t_info info)
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

int	ft_puthex_fd(int fd, long long num, t_info info)
{
	long long	temp;
	char		prt[30];
	int			idx;

	idx = 0;
	ft_memset(prt, 0, 30);
	temp = num;
	if (!num)
		return (ft_putchar_fd(fd, '0'));
	while (temp)
	{
		prt[idx] = temp % 16 + '0';
		if (prt[idx] > '9')
			prt[idx] = prt[idx] - '0' - 10 + 'A';
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