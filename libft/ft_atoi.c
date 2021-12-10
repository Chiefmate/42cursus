/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:55:58 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/10 16:12:56 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	make_n(const char *s, int neg_sign)
{
	long long	n;

	n = 0;
	while (ft_isdigit(*s))
	{
		n = 10 * n - (*s++ - '0');
		if (n > 2147483647 && !neg_sign)
			return (2147483647);
		else if (n > 2147483648 && neg_sign)
			return (-2147483648);
	}
	if (neg_sign)
		return (n);
	return (-n);
}

//  ft_isdigit() used
int	ft_atoi(const char *s)
{
	long long	n;
	int			neg_sign;

	neg_sign = 0;
	while (*s == ' ' || *s == '\f' || *s == '\n' || \
	*s == '\r' || *s == '\t' || *s == '\v')
		s++;
	if (*s == '-')
	{
		neg_sign = 1;
		s++;
	}
	else if (*s == '+')
		s++;
	return ((int)make_n(s, neg_sign));
}
