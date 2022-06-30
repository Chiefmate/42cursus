/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:44:32 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/27 20:44:34 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 *	concatenate a and b, which is of length of c_size
 */
char	*make_ret(char *a, char *b, ssize_t c_size)
{
	char	*ret;
	size_t	len_a;

	if (!a)
		a = ft_strdup("");
	len_a = 0;
	while (a[len_a])
		len_a++;
	ret = (char *)malloc(sizeof(char) * (len_a + c_size + 1));
	ft_memcpy(ret, a, len_a);
	ft_memcpy(ret + len_a, b, c_size);
	ret[len_a + c_size] = '\0';
	free(a);
	a = NULL;
	return (ret);
}

/*
 *	initialize buffer
 */
int	init_buf(int fd, char *buf, char *keep_fd)
{
	ssize_t	r_size;

	if (!keep_fd[0])
	{
		r_size = read(fd, buf, BUFFER_SIZE);
	}
	else
	{
		r_size = ft_strnlen(keep_fd, BUFFER_SIZE);
		ft_memcpy(buf, keep_fd, r_size);
		ft_memset(keep_fd, 0, r_size);
	}
	return (r_size);
}

/*
 * exit if possible
 */
char	*check_ret(char *ret, char *buf, char *keep_fd, ssize_t r_size)
{
	char	*offset;

	offset = ft_memchr(buf, '\n', r_size);
	if (offset)
	{
		ret = make_ret(ret, buf, offset - buf + 1);
		ft_memset(keep_fd, 0, BUFFER_SIZE);
		if (r_size - (offset - buf) >= 1)
			ft_memcpy(keep_fd, offset + 1, r_size - (offset - buf) - 1);
		ft_memset(buf, 0, BUFFER_SIZE);
		return (ret);
	}
	ret = make_ret(ret, buf, r_size);
	return (ret);
}

char	*solve(int fd, char *ret, char *buf, char *keep_fd)
{
	ssize_t	r_size;

	r_size = init_buf(fd, buf, keep_fd);
	while (r_size > 0)
	{
		ret = check_ret(ret, buf, keep_fd, r_size);
		if (!buf[0])
			break ;
		r_size = read(fd, buf, BUFFER_SIZE);
	}
	if (!r_size)
		ft_memset(keep_fd, 0, BUFFER_SIZE);
	if (r_size < 0 && ret)
	{
		free(ret);
		ret = NULL;
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	keep[OPEN_MAX][BUFFER_SIZE];
	char		*ret;

	if (fd > OPEN_MAX || fd < 0)
		return (0);
	ret = NULL;
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (0);
	ft_memset(buf, 0, BUFFER_SIZE);
	ret = solve(fd, ret, buf, keep[fd]);
	free(buf);
	buf = NULL;
	return (ret);
}
