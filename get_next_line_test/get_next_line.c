/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:40:41 by hyunhole          #+#    #+#             */
/*   Updated: 2022/01/16 15:52:30 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

void	make_keep(char keep[], char *buf, ssize_t c_size)
{
	ft_memset(keep, 0, BUFFER_SIZE);
	ft_memcpy(keep, buf, c_size);
	return ;
}

char	*make_ret(char *a, char *b, ssize_t c_size)
{
	char	*ret;
	size_t	len_a;

	if (!a)
		a = ft_strdup("");
	len_a = ft_strlen(a);
	ret = (char *)malloc(sizeof(char) * (len_a + c_size + 1));
	ft_memcpy(ret, a, len_a);
	ft_memcpy(ret + len_a, b, c_size);
	ret[len_a + c_size] = '\0';
	free(a);
	a = NULL;
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	keep[OPEN_MAX][BUFFER_SIZE];
	ssize_t		r_size;
	char		*ret;
	char		*offset;

	ret = NULL;
	offset = 0;
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (0);
	ft_memset(buf, 0, BUFFER_SIZE);
	if (!(keep[fd]))
	{
		r_size = read(fd, buf, BUFFER_SIZE);
	}
	else
	{
		ft_memcpy(buf, keep[fd], BUFFER_SIZE);
		r_size = ft_strnlen(buf, BUFFER_SIZE);
	}
	while (r_size >= 0)
	{
		offset = ft_memchr(buf, '\n', r_size);
		if (offset || r_size < BUFFER_SIZE)
		{
			make_ret(ret, buf, r_size);
			if (offset)
				make_keep(keep[fd], buf, r_size - (offset - buf));
			free(buf);
			buf = NULL;
			return (ret);
		}
		make_ret(ret, buf, r_size);
		r_size = read(fd, buf, BUFFER_SIZE);
	}
	if (ret)
	{
		free(ret);
		ret = NULL;
	}
	free(buf);
	buf = NULL;
	return (NULL);
}
