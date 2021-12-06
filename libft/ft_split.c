/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:59:53 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/07 02:53:13 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

static void	make_ret(char const *s, char c, char **ret, int *idxarr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (idxarr[i++] != -2)
	{
		if (idxarr[i + 1] - 1 < idxarr[i] + 1)
			continue ;
		ret[j++] = ft_substr(s, idxarr[i] + 1, \
			idxarr[i + 1] - idxarr[i] - 1);
	}
	return ;
}

//	ft_memset, ft_substr, ft_strlen used
char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		ret_len;
	int		i;
	int		*idxarr;

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
	idxarr = (int *)malloc(sizeof(int) * (ret_len + 1));
	if (!idxarr)
		return ((void *)0);
	ft_memset(ret, 0, sizeof(char *) * (ret_len + 1));
	ft_memset(idxarr, -2, sizeof(int) * (ret_len + 1));
	idxarr[0] = -1;
	make_ret(s, c, ret, idxarr);
	return (ret);
}

int	main(void)
{
	char	**a;

	a = ft_split("ab1cd2ef", '1');
	printf("%s\n", a[0]);
	return (0);
}
