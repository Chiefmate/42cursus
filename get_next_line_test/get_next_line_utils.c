/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:40:48 by hyunhole          #+#    #+#             */
/*   Updated: 2022/01/16 15:02:25 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memchr(const void *buf, int c, size_t count)
{
	unsigned char	*ret;

	ret = (unsigned char *)buf;
	while (count && *ret != (unsigned char)c)
	{
		count--;
		ret++;
	}
	if (!count)
		return (0);
	return ((void *)ret);
}

//	ft_memchr used
size_t	ft_strnlen(char *str, size_t n)
{
	char	*part;

	part = ft_memchr(str, 0, n);
	if (!part)
		return (n);
	else
		return (part - str);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			idx;

	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	idx = 0;
	if (d < s)
	{
		while (idx < n)
		{
			d[idx] = s[idx];
			idx++;
		}
	}
	else if (d > s)
	{
		idx = n;
		while (idx > 0)
		{
			idx--;
			d[idx] = s[idx];
		}
	}
	return (dst);
}

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*s;
	size_t			k;

	s = (unsigned char *)b;
	k = 0;
	while (k < n)
	{
		s[k] = c;
		k++;
	}
	return (b);
}

//  ft_strlen used
char	*ft_strdup(const char *s)
{
	char	*ret;
	size_t	idx;
	size_t	s_len;

	s_len = 0;
	while (s[s_len])
		s_len++;
	ret = (char *)malloc(sizeof(char) * (s_len + 1));
	if (ret == (void *)0)
		return (ret);
	idx = 0;
	while (idx < s_len)
	{
		ret[idx] = s[idx];
		idx++;
	}
	ret[idx] = '\0';
	return (ret);
}
