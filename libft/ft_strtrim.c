/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:59:20 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/03 16:43:40 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//  ft_strlcpy used
char	*ft_strtrim(char const *s1, char const *set)
{
	char			*ret;
	unsigned int	idx;
	unsigned int	len;
	unsigned int	i;

	len = ft_strlen(s1);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return ((void *)0);
	if (ft_strlcpy(ret, s1, len + 1) > len + 1)
		return ((void *)0);
	idx = -1;
	while (++idx < len && *s1 != '\0')
	{
		i = -1;
		while (++i < ft_strlen(set))
		{
			if (*s1 == set[i])
				s1++;
		}
		ret[idx] = *s1;
	}
	if (ret[idx - 1] != '\0')
		ret[idx] = '\0';
	return (ret);
}
