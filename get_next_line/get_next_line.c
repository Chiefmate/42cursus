/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:53:15 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/22 17:39:42 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

/*
 * if \n is not there in buf, offset = r_size;
 */
ssize_t get_offset(char *buf, ssize_t r_size)
{
	ssize_t	i;
	ssize_t	offset;

	offset = r_size - 1;
	i = 0;
	while (i < r_size)
	{
		if (buf[i] == '\n')
		{
			offset = i;
			break ;
		}
		i++;
	}
	return (offset);
}

/*
 * save_backup saves leftover buf into backup[fd] 
 */
char	*save_backup(char *backup, char *buf, ssize_t r_size, ssize_t offset)
{
	char	*new;
	size_t	bu_len;

	bu_len = 0;
	while (backup[bu_len])
		bu_len++;
	new = (char *)malloc(sizeof(char) * (r_size - offset + bu_len));
	if (!new)
		return (NULL);
	ft_memcpy(new, buf + offset + 1, r_size - offset - 1);
	ft_memcpy(new + r_size - offset, backup, bu_len + 1);
	free(backup);
	return (new);
}

/*
 * if buf has '\n'
 * or r_size < BUFFER_SIZE
 */
int	is_time_2_ret(char *buf, ssize_t r_size)
{
	if (r_size < BUFFER_SIZE)
		return (1);
	while (--r_size >= 0)
	{
		if (buf[r_size] == '\n')
			return (1);
	}
	return (0);
}

char	*trim_backup(char *backup, ssize_t r_size)
{
	size_t	newlen;
	char	*new;

	newlen = r_size;
	while (backup[newlen])
		newlen++;
	newlen -= r_size;
	new = (char *)malloc(sizeof(char) * (newlen + 1));
	ft_memcpy(new, backup + r_size, newlen);
	backup[newlen] = '\0';
	free(backup);
	return (new);
}

/*
 * backup[fd] alwways ends with nul-terminator
 * but buffer does NOT end with nul-terminator
 */
char	*get_next_line(int fd)
{
	char		*buf;
	ssize_t		r_size;
	static char	*backup[OPEN_MAX];
	ssize_t		offset;
	char		*ret;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (0);
	ft_memset(buf, 0, BUFFER_SIZE);
	ret = NULL;
	if (!backup[fd] || backup[fd])
	{
		r_size = read(fd, buf, BUFFER_SIZE);
		if (r_size == -1)
		{
			free(buf);
			return (0);
		}
	}
	else
	{
		r_size = ft_datalen(backup[fd]);
		ft_memcpy(buf, backup[fd], r_size);
		backup[fd] = trim_backup(backup[fd], r_size);
	}
	offset = r_size;
	while (r_size > 0)
	{
		if (is_time_2_ret(buf, r_size))
		{
			offset = get_offset(buf, r_size);
			backup[fd] = save_backup(backup[fd], buf, r_size, offset);
			ret = join_ret_buf(ret, buf, offset);
			free(buf);
			return (ret);
		}
		offset = r_size - 1;
		ret = join_ret_buf(ret, buf, offset);
		r_size = read(fd, buf, BUFFER_SIZE);
		if (r_size == -1)
		{
			free(ret);
			free(buf);
			return (0);
		}
	}

	/* r_size == 0 이라 넘어왔을 때 처리 필요 */
	backup[fd] = save_backup(backup[fd], buf, r_size, offset);
	free(buf);
	return (ret);
}
