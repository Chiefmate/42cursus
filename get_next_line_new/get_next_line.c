/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:40:41 by hyunhole          #+#    #+#             */
/*   Updated: 2022/01/04 17:34:40 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_keep(char *buf, char *keep)
{
	ssize_t	r_size;

	r_size = ft_strnlen(buf, 0);

	ft_memcpy(buf, keep, r_size * sizeof(char));

	
}

/*
 *	strnlen, memset, memcpy
 */
char	*get_next_line(int fd)
{
	char		*buf;
	static char	*keep[OPEN_MAX];
	ssize_t		r_size;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (0);
	ft_memset(buf, 0, BUFFER_SIZE);

	if (!(keep[fd]) || *(keep[fd]))
	{
		/* keep is empty */
		r_size = read(fd, buf, BUFFER_SIZE);	
	}
	else
	{
		/* keep data exists */
		ft_memcpy(buf, keep[fd], BUFFER_SIZE);

	}
	/* ret */


	/* cont */

	/* read */
}
