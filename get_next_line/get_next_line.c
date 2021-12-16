/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:53:15 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/15 21:21:50 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * is_buf_end returns
 * 1 if this buf should be the last one:	'\n' is there in buf
 * 											OR ('\n' is not there && r_size < BUFFER_SIZE)
 * 											OR error has occured (r_size < 0 etc..)
 * 0 if this buf is not the last one:		'\n' is not there && r_size == BUFFER_SIZE
 */

int	is_buf_end(char *buf, ssize_t r_size)
{
	ssize_t	i;

	if (r_size <= 0 || !buf)
		return (1);
	i = 0;
	while (i < r_size)
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/*
 * strlcpy, strlen used
 */

void	ft_strjoin_sub(char **ret, char *buf, ssize_t r_size)
{
	char	*temp;
	ssize_t	i;

	temp = (char *)malloc(sizeof(char) * (ft_strlen(*ret) + r_size));
	ft_strlcpy(temp, *ret, ft_strlen(*ret));
	ft_strlcpy(temp + ft_strlen(*ret), buf, ft_strlen(*ret) + r_size);
	free(*ret);
	*ret = temp;
	return ;
}

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

char	*get_next_line(int fd)
{
	char		*buf[BUFFER_SIZE];
	ssize_t		r_size;
	static char	*backup[OPEN_MAX];
	ssize_t		offset;
	char		*ret;

	ret = ft_strdup("");
	offset = 0;
	r_size = ft_strlen(backup[fd]);
	ft_strlcpy(buf, backup[fd], r_size);

	while (!is_buf_end(buf, r_size))
	{
		offset = get_offset(buf, r_size);
		ft_strjoin_sub(&ret, buf, r_size);
		free(backup[fd]);
		backup[fd] = ft_substr(buf, offset, BUFFER_SIZE - r_size);
		
		
		r_size = read(fd, buf, BUFFER_SIZE);
		if (r_size == -1)
		{
			free(ret);	
			return (0);
		}
	}


	return (ret);
}
