/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:00:26 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/03 16:00:38 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//  ft_isdigit used
char	*ft_itoa(int n)
{
	char		*ret;
	long long	abs;
	int			digits;
	char		pmsign;
	long long	j;

	pmsign = 1;
	if (n < 0)
	{
		pmsign = -1;
		abs = -n;
	}
	else
		abs = n;
	digits = 1;
	j = abs;
	while (j / 10 != 0)
	{
		j /= 10;
		digits++;
	}
	ret = (char *)malloc(sizeof(char) * (digits + 1));
	if (pmsign == -1)
		digits++;
	while (digits != 0)
	{
		ret[digits - 1] = abs;
		abs = abs / 10;
		digits--;
	}
	if (pmsign == -1)
		ret[0] = '-';
	return (ret);
}