/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:56:54 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/03 16:40:55 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	size_t			idx;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)buf1;
	p2 = (unsigned char *)buf2;
	idx = 0;
	while (idx < count && p1[idx] == p2[idx])
		idx++;
	return (p1[idx] - p2[idx]);
}
