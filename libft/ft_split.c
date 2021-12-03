/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:59:53 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/03 16:00:12 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	ft_memset, ft_substr, ft_strlen used
char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		ret_len;
	int		i;
	int		j;
	int		*bpoint;

	ret_len = 1;
	i = -1;
	while (++i < ft_strlen(s))
	{
		if (s[i] == c)
			ret_len++;
	}
	ret = (char **)malloc(sizeof(char *) * (ret_len + 1));
	if (!ret)
		return ((void *)0);
	bpoint = (int *)malloc(sizeof(int) * (ret_len + 1));
	if (!bpoint)
		return ((void *)0);
	ft_memset(bpoint, -2, sizeof(int));
	bpoint[0] = -1;
	j = 1;
	i = -1;
	while (++i < ret_len)
	{
		if (s[i] == c)
			bpoint[j++] = i;
	}
	i = -1;
	j = 0;
	while (bpoint[++i] != -2)
	{
		if (bpoint[i + 1] - 1 < bpoint[i] + 1)
			continue ;
		ret[j++] = ft_substr(s, bpoint[i] + 1, bpoint[i + 1] - bpoint[i] - 1);
	}
	ret[j] = (void *)0;
	return (ret);
}