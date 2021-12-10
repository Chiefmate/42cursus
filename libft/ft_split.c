/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:59:53 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/10 21:34:29 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	make_ret(char const *s, char **ret, int *idxarr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (idxarr[i] != ft_strlen(s))
	{
		if ((idxarr[i] + 1) > (idxarr[i + 1] - 1))
		{
			i++;
			continue ;
		}
		ret[j] = ft_substr(s, idxarr[i] + 1, \
			idxarr[i + 1] - idxarr[i] - 1);
		j++;
		i++;
	}
	return ;
}

static void	make_idxarr(char const *s, char c, int *idxarr)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	idxarr[0] = -1;
	while (s[i])
	{
		if (s[i] == c)
		{
			idxarr[j] = i;
			j++;
		}
		i++;
	}
	idxarr[j] = ft_strlen(s);
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
	idxarr = (int *)malloc(sizeof(int) * (ret_len + 2));
	if (!idxarr)
		return ((void *)0);
	ft_memset(ret, 0, sizeof(char *) * (ret_len + 1));
	ft_memset(idxarr, 0, sizeof(int) * (ret_len + 2));
	make_idxarr(s, c, idxarr);
	make_ret(s, ret, idxarr);
	free(idxarr);
	return (ret);
}
