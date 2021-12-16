/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:53:30 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/16 18:39:51 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * concatenate ret and a part of buf, buf[0]~buf[offset]
 */

char	*join_ret_buf(char *ret, char *buf, ssize_t offset)
{
	char	*temp;

	temp = (char *)malloc(sizeof(char) * (ft_strlen(ret) + offset + 2));
	ft_strlcpy(temp, ret, ft_strlen(ret) + 1);
	ft_strlcpy(temp + ft_strlen(ret), buf, offset + 2);
	free(ret);
	return (temp);
}

size_t	ft_strlen(const char *s)
{
	const char	*temp;
	size_t		len;

	if (!s)
		return (0);
	len = 0;
	temp = s;
	while (*temp)
	{
		temp++;
		len++;
	}
	return (len);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (!size || !src)
		return (src_len);
	size--;
	while (*src && size)
	{
		*dest = *src;
		size--;
		dest++;
		src++;
	}
	*dest = '\0';
	return (src_len);
}

char	*get_backup(char *buf, ssize_t offset, ssize_t r_size)
{
	char	*ret;
	ssize_t	len;

	if (offset == r_size - 1)
		return (ft_strdup(""));
	len = r_size - offset - 1;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	ft_strlcpy(ret, buf + offset + 1, len + 1);
	return (ret);
}

//  ft_strlen used
char	*ft_strdup(const char *s)
{
	char	*ret;
	size_t	idx;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (ret == (void *)0)
		return (ret);
	idx = 0;
	while (idx < ft_strlen(s))
	{
		ret[idx] = s[idx];
		idx++;
	}
	ret[idx] = '\0';
	return (ret);
}
