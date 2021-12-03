/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:01:27 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/03 16:42:23 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char			*tempptr;
	unsigned int	idx;

	idx = 0;
	tempptr = s;
	while (*tempptr)
	{
		f(idx, tempptr);
		idx++;
		tempptr++;
	}
	return ;
}
