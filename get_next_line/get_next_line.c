/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:53:15 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/16 21:00:46 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

/*
 * get_offset returns
 * - the index of \n, if \n exists
 * - r_size, if \n does not exist
 */
ssize_t	get_offset(char *buf, ssize_t r_size)
{
	ssize_t	i;

	i = 0;
	while (i < r_size)
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (r_size);
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
 * read_buf reads backup or buf, and returns
 * r_size, which equals to the size of the read size
 */
ssize_t	read_buf(int fd, char *buf, char **backup)
{
	ssize_t	r_size;

	if (!backup[fd] || !(*(backup[fd])))
		ft_strlcpy(buf, backup[fd], BUFFER_SIZE);
	else if (ft_strlen(backup[fd]))
		ft_strlcpy(buf
	else
	{
		r_size = read(fd, buf, BUFFER_SIZE);
	}
	return (r_size);
}

char	*get_next_line(int fd)
{
	char		*buf;
	ssize_t		r_size;
	static char	**backup[OPEN_MAX];
	ssize_t		offset;
	char		*ret;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	ret = NULL;
	r_size = ft_strlen(backup[fd]);
	if (!r_size)
	{
		r_size = read(fd, buf, BUFFER_SIZE);
		if (r_size == -1)
		{
			free(backup[fd]);
			backup[fd] = 0;
			free(buf);
			return (0);
		}
		buf[r_size] = '\0';
	}
	else
		ft_strlcpy(buf, backup[fd], r_size + 1);


	while (r_size)
	{
		if (is_lb(buf, r_size))
		{
			offset = get_offset(buf, r_size);
			free(backup[fd]);
			backup[fd] = get_backup(buf, offset, r_size);
			ret = join_ret_buf(ret, buf, offset);
			free(buf);
			return (ret);
		}


		offset = r_size;
		ret = join_ret_buf(ret, buf, offset);
		r_size = read(fd, buf, BUFFER_SIZE);
		buf[r_size] = '\0';
		if (r_size == -1)
		{
			free(backup[fd]);
			backup[fd] = ft_strdup("");
			free(ret);
			free(buf);
			return (0);
		}
	}
	free(buf);
	return (ret);
}
