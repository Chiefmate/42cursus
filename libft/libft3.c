/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:08:37 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/03 12:13:57 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//  strlcpy, strlcat use ft_strlen
size_t  ft_strlcpy(char *dest, const char *src, size_t size)
{
	char	*d;
	size_t  idx;

	d = dest;
	idx = 0;
	if (!size)
		return (ft_strlen(src));
	while (src[idx] && idx + 1 < size)
	{
		d[idx] = src[idx];
		idx++;
	}
	d[idx] = '\0';
	return (ft_strlen(src));
}

size_t  ft_strlcat(char *dest, const char *src, size_t size)
{
	char	*d;
	size_t  idx;

	d = dest;
	idx = 0;
	if (!size)
		return (ft_strlen(src) + ft_strlen(dest));
	while (*d)
		d++;
	while (src[idx] && idx + ft_strlen(dest) + 1 < size)
	{
		d[idx] = src[idx];
		idx++;
	}
	d[idx] = '\0';
	return (ft_strlen(src) + ft_strlen(dest));
}

int ft_toupper(int c)
{
	if ((unsigned)c - 'A' < 26)
		return (c - 32);
	return (c);
}

int ft_tolower(int c)
{
	if ((unsigned)c - 'a' < 26)
		return (c + 32);
	return (c);
}
