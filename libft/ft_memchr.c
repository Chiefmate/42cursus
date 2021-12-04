/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:56:36 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/04 16:31:15 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t count)
{
	unsigned char	*ptr;
	unsigned char	*ret;
	size_t			idx;

	ptr = (unsigned char *)buf;
	ret = NULL;
	idx = 0;
	while (*ptr && idx < count)
	{
		if (*ptr == (unsigned char)c)
		{
			ret = ptr;
			break ;
		}
		idx++;
		ptr++;
	}
	return ((void *)ret);
}
