/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:58:31 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/10 12:03:55 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	strlen used
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	idx;

	if (!s || start >= ft_strlen(s))
		return (0);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	idx = start;
	while (idx - start < len && s[idx])
	{
		ret[idx - start] = s[idx];
		idx++;
	}
	ret[idx - start] = '\0';
	return (ret);
}
