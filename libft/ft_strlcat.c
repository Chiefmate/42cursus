/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:53:17 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/03 16:42:37 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char	*d;
	size_t	idx;

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
