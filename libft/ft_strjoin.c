/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:58:56 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/03 15:59:06 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//  ft_strlen used
char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ret;
	unsigned int	idx;
	unsigned int	s1_len;
	unsigned int	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!ret)
		return ((void *)0);
	idx = -1;
	while (++idx < s1_len)
		ret[idx] = s1[idx];
	while (idx++ < s1_len + s2_len)
		ret[idx] = s2[idx - s1_len];
	ret[idx] = '\0';
	return (ret);
}