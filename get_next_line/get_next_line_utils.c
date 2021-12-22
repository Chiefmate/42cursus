/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:12:25 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/22 17:03:07 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_ret_buf(char *ret, char *buf, ssize_t offset)
{
	size_t	ret_len;
	char	*temp;
	
	if (!ret)
		ret = ft_strdup("");
	ret_len = 0;
	while (ret[ret_len])
		ret_len++;
	temp = (char *)malloc(sizeof(char) * (ret_len + offset + 2));
	ft_memcpy(temp, ret, ret_len);
	ft_memcpy(temp + ret_len, buf, offset + 1);
	temp[ret_len + offset + 1] = '\0';
	free(ret);
	return (temp);
}

/*
 * MAX = BUFFER_SIZE
 */
size_t	ft_datalen(const char *s)
{
	char	*temp;
	size_t	len;

	len = 0;
	temp = (char *)s;
	while (temp[len] && len < BUFFER_SIZE)
	{
		len++;
	}
	return (len);
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
