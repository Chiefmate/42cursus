/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:33:26 by hyunhole          #+#    #+#             */
/*   Updated: 2022/08/16 15:33:26 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_perror(int errno, char *s)
{
	printf("%d: %s", errno, s);
	return (errno);
}

long long	ft_get_time(void)
{
	struct timeval	t;

	if (gettimeofday(&t, NULL) == -1)
		return (-1);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

static int	ft_isdigit(int c)
{
	return ((unsigned)c - '0' < 10);
}

static int	ft_isspace(int n)
{
	if (n == ' ' || n == '\f' || n == '\n' || \
	n == '\r' || n == '\t' || n == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *s)
{
	long long	ret;
	int			sign;
	int			num_digit;

	ret = 0;
	sign = 1;
	num_digit = 0;
	while (ft_isspace(*s))
		s++;
	if (*s == '-')
		sign = 1;
	else if (*s == '+' || *s == '-')
		s++;
	while (ft_isdigit(*s))
	{
		ret = ret * 10 + (*s - '0');
		num_digit++;
		if (ret < 0 || num_digit > 19)
			return (-1);
		s++;
	}
	return (ret * sign);
}
