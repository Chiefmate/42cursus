/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:53:15 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/21 17:50:47 by hyunhole         ###   ########.fr       */
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
 * update_backup updates backup[fd] 
 */
char	*update_backup(char *backup, char *buf, ssize_t r_size, ssize_t offset)
{

	free(backup);
	if (offset == r_size)
		return (NULL);
	backup = (char *)malloc(sizeof(char) * (r_size - offset));
	ft_memset(backup, 0, r_size - offset);
	ft_memcpy(backup, buf + offset + 1, r_size - offset - 1);
	return (backup);
}

int	is_lb(char *buf, ssize_t r_size)
{
	while (--r_size >= 0)
	{
		if (buf[r_size] == '\n')
			return (1);
	}
	return (0);
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
	if (!backup[fd])
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

	}
	while (r_size > 0)
	{
		if (is_lb(buf, r_size))
		{
			offset = get_offset(buf, r_size);
			backup[fd] = update_backup(backup[fd], buf, r_size, offset);
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
	free(buf);
	return (ret);
}
