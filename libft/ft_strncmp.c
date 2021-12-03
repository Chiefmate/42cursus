/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:55:12 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/03 15:55:26 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		ret;
	size_t	idx;

	idx = 0;
	while (idx < n && s1[idx] && s1[idx] != s2[idx])
		idx++;
	ret = s1[idx] - s2[idx];
	return (ret);
}