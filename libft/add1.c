/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:52:16 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/03 12:11:07 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	idx;

	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return ((void *)0);
	idx = start;
	while (idx < len && s[idx])
	{
		ret[idx - start] = s[idx];
		idx++;
	}
	return (ret);
}

//  ft_strlen used
char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ret;
	unsigned int	idx;
	unsigned int	s1_len;
	unsigned int	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(ret = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return ((void *)0);
	idx = 0;
	while (idx < s1_len)
	{
		ret[idx] = s1[idx];
		idx++;
	}
	while (idx < s1_len + s2_len)
	{
		ret[idx] = s2[idx - s1_len];
		idx++;
	}
	ret[idx] = '\0';
	return (ret);
}

//  ft_strlcpy used
char	*ft_strtrim(char const *s1, char const *set)
{
	char			*ret;
	char			*cursor;
	unsigned int	idx;
	unsigned int	len;
	unsigned int	i;

	len = ft_strlen(s1);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return ((void *)0);
	if (ft_strlcpy(ret, s1, len + 1) > len + 1)
		return ((void *)0);
	cursor = (char *)s1;
	idx = 0;
	while (idx < len && *cursor != '\0')
	{
		i = -1;
		while (++i < ft_strlen(set))
		{
			if (*cursor == set[i])
				cursor++;
		}
		ret[idx] = *cursor;
		idx++;
	}
	if (ret[idx - 1] != '\0')
		ret[idx] = '\0';
	return (ret);
}

//	ft_memset, ft_substr, ft_strlen used
char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		ret_len;
	int		i;
	int	 j;
	int	 *breakpoints;

	ret_len = 1;
	i = -1;
	while (++i < ft_strlen(s))
	{
		if (s[i] == c)
			ret_len++;
	}
	if (!(ret = (char **)malloc(sizeof(char *) * (ret_len + 1))))
		return ((void *)0);
	if (!(breakpoints = (int *)malloc(sizeof(int) * (ret_len + 1))))
		return ((void *)0);
	ft_memset(breakpoints, -2, sizeof(int));
	breakpoints[0] = -1;
	j = 1;
	i = -1;
	while (++i < ret_len)
	{
		if (s[i] == c)
		{
			breakpoints[j] = i;
			j++;
		}
	}
	i = -1;
	j = 0;
	while (breakpoints[++i] != -2)
	{
		if (breakpoints[i + 1] - 1 < breakpoints[i] + 1)
			continue;
		ret[j] = ft_substr(s, breakpoints[i] + 1, breakpoints[i + 1] - breakpoints[i] - 1);
		j++;
	}
	ret[j] = (void *)0;
	return (ret);
}

//  ft_isdigit used
char	*ft_itoa(int n)
{
	char		*ret;
	long long   abs;
	int		 digits;
	char		pmsign;
	long long   j;

	pmsign = 1;
	if (n < 0)
	{
		pmsign = -1;
		abs = -n;
	}
	else
		abs = n;
	digits = 1;
	j = abs;
	while (j / 10 != 0)
	{
		j /= 10;
		digits++;
	}
	ret = (char *)malloc(sizeof(char) * (digits + 1));
	if (pmsign == -1)
		digits++;
	while (digits != 0)
	{
		ret[digits - 1] = abs;
		abs = abs / 10;
		digits--;
	}
	if (pmsign == -1)
		ret[0] = '-';
	return (ret);
}
