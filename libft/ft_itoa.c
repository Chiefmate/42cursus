/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:00:26 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/10 12:17:52 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*parse_ret(char pmsign, char *org_ret)
{
	char	*ret;
	size_t	size;
	size_t	i;

	size = 0;
	while (*(org_ret + size) != -1)
		size++;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (0);
	i = 0;
	if (pmsign < 0)
	{
		ret[0] = '-';
		i++;
	}
	while (size > 0)
	{	
		ret[i++] = '0' + org_ret[size - 1];
		size--;
	}
	ret[i] = '\0';
	return (ret);
}

static void	make_ret(int n, char pmsign, char *org_ret)
{
	size_t	i;
	char	not_last;

	not_last = 1;
	i = 0;
	while (n || not_last)
	{
		org_ret[i++] = pmsign * (char)(n % 10);
		not_last = 0;
		if ((-100 < n && n < -9) || (9 < n && n < 100))
			not_last = 1;
		n /= 10;
	}
	return ;
}

//  ft_isdigit used
char	*ft_itoa(int n)
{
	char	*org_ret;
	char	*ret;
	char	pmsign;
	int		i;

	org_ret = (char *)malloc(sizeof(char) * 12);
	if (!org_ret)
		return (0);
	i = -1;
	while (++i < 12)
		org_ret[i] = -1;
	if (n < 0)
		pmsign = -1;
	else
		pmsign = 1;
	make_ret(n, pmsign, org_ret);
	ret = parse_ret(pmsign, org_ret);
	free(org_ret);
	return (ret);
}
