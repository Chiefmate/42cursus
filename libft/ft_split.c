/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:59:53 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/11 12:50:00 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_ret(char **ret, int j)
{
	int	k;

	k = -1;
	while (++k < j)
		free(ret[j]);
	return ;
}

static int	make_ret(char const *s, char **ret, int *idxarr)
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
		if (!ret[j])
		{
			free_ret(ret, j);
			free(idxarr);
			return (1);
		}
		j++;
		i++;
	}
	free(idxarr);
	return (0);
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

static unsigned int	count_substr(char const *s, char c)
{
	unsigned int	ret_len;
	unsigned int	i;
	char			is_f_by_c;

	is_f_by_c = 1;
	ret_len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			is_f_by_c = 1;
		else if (s[i] != c && is_f_by_c)
			ret_len++;
		if (s[i] != c)
			is_f_by_c = 0;
		i++;
	}
	return (ret_len);
}

//	ft_memset, ft_substr, ft_strlen used
char	**ft_split(char const *s, char c)
{
	char			**ret;
	unsigned int	ret_len;
	int				*idxarr;

	if (!s)
		return (0);
	ret_len = count_substr(s, c);
	ret = (char **)malloc(sizeof(char *) * (ret_len + 1));
	if (!ret)
		return (0);
	idxarr = (int *)malloc(sizeof(int) * (ft_strlen(s) + 1));
	if (!idxarr)
	{
		free(ret);
		return (0);
	}
	ft_memset(ret, 0, sizeof(char *) * (ret_len + 1));
	ft_memset(idxarr, 0, sizeof(int) * (ft_strlen(s) + 1));
	make_idxarr(s, c, idxarr);
	if (make_ret(s, ret, idxarr) == 1)
	{
		free(ret);
		return (0);
	}
	return (ret);
}
