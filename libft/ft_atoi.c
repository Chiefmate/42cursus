/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:55:58 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/07 01:05:19 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//  ft_isdigit() used
int	ft_atoi(const char *s)
{
	int		 n;
	int		 neg_sign;

	n = 0;
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
	while (ft_isdigit(*s))
		n = 10 * n - (*s++ - '0');
	if (neg_sign)
		return (n);
	return (-n);
}
