/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:52:47 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/03 16:42:46 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//  strlcpy, strlcat use ft_strlen
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	char	*d;
	size_t	idx;

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
