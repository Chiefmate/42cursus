/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:52:16 by hyunhole          #+#    #+#             */
/*   Updated: 2021/11/23 13:25:46 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char            *ret;
    unsigned int    idx;

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
char    *ft_strjoin(char const *s1, char const *s2)
{
    char            *ret;
    unsigned int    idx;
    unsigned int    s1_len;
    unsigned int    s2_len;

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
char    *ft_strtrim(char const *s1, char const *set)
{
    char            *ret;
    char            *cursor;
    unsigned int    idx;
    unsigned int    len;
    unsigned int    i;

    len = ft_strlen(s1);
    if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
        return ((void *)0);
    if (ft_strlcpy(ret, s1, len + 1) > len + 1)
        return ((void *)0);
    cursor = s1;
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

//	ft_strrchr ft_strlen used
char    **ft_split(char const *s, char c)
{
	char	**ret;
	int		ret_len;
	int		i;

	i = -1;
	while (++i < ft_strlen(s))
	{
		if (s[i] == c)
			ret_len++;
	}

	ft_strrchr(s, c);
}

ft_itoa
