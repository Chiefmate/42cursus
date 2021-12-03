/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:59:53 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/03 16:42:04 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_retlen_bpoint(char const *s, char c, int **bpointptr)
{
	int	i;
	int	j;
	int	ret_len;

	ret_len = 1;
	i = -1;
	while (++i < ft_strlen(s))
	{
		if (s[i] == c)
			ret_len++;
	}
	j = 1;
	i = -1;
	while (++i < ret_len)
	{
		if (s[i] == c)
			(*bpointptr)[j++] = i;
	}
	return (ret_len);
}

static void	makeret(char const *s, char c, char ***retptr, int **bpointptr)
{
	int	i;
	int	j;
	int	ret_len;

	ret_len = get_retlen_bpoint(s, c, bpointptr);
	i = -1;
	j = 0;
	while ((*bpointptr)[++i] != -2)
	{
		if ((*bpointptr)[i + 1] - 1 < (*bpointptr)[i] + 1)
			continue ;
		(*retptr)[j++] = ft_substr(s, (*bpointptr)[i] + 1, \
			(*bpointptr)[i + 1] - (*bpointptr)[i] - 1);
	}
	(*retptr)[j] = (void *)0;
	return ;
}

//	ft_memset, ft_substr, ft_strlen used
char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		ret_len;
	int		i;
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
	makeret(s, c, &ret, &bpoint);
	return (ret);
}
