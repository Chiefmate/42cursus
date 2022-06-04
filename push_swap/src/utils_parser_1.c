/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:52:29 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/04 19:04:33 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../libft/libft.h"

#define	OVERFLOW	-2147483649

static int	ft_isspace(int n)
{
	if (n == ' ' || n == '\f' || n == '\n' || \
	n == '\r' || n == '\t' || n == '\v')
		return (1);
	return (0);
}

static long long	make_n(const char *s, char is_neg)
{
	long long	n;

	n = 0;
	while (ft_isdigit(*s))
	{
		n = 10 * n + (*s++ - '0');
		if (n >= 100000000000000000 && !is_neg && (*s > LONG_MAX % 10))
			return (OVERFLOW);
		else if (n >= 100000000000000000 && is_neg \
				&& (*s > ((-1) * (LONG_MIN % 10))))
			return (OVERFLOW);
	}
	if (is_neg)
		return (-n);
	return (n);
}

//  ft_isdigit() used, limits.h included for LONG_MAX, LONG_MIN
int	ft_atoi_sp(const char *s, int *ret)
{
	char		is_neg;
	long long	temp;

	is_neg = 0;
	while (ft_isspace(*s))
		s++;
	if (*s == '-')
	{
		is_neg = 1;
		s++;
	}
	else if (*s == '+')
		s++;
	temp = make_n(s, is_neg);
	if (temp == OVERFLOW)
		return (0);
	*ret = (int)temp;	
	return (1);
}
