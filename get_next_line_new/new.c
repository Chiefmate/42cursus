/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:39:06 by hyunhole          #+#    #+#             */
/*   Updated: 2022/01/04 17:39:06 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_backup(char *s);
int		read_file(int fd, char *buf);
int		is_end_of_func(char *buf, int r_size);		// use memchr
char	*save_backup(char *buf, int r_size);		// replacable with substr() and free()
char	*make_ret(char *ret, char *buf);

char	*get_next_line(int fd)
{
	static char *backup[OPEN_MAX];
	char		buf[BUFFER_SIZE];
	int			r_size;
	char		*ret;

	ret = NULL;
	ft_memset(buf, 0, BUFFER_SIZE);
	r_size = check_backup(backup[fd]);
	if (!r_size)
		r_size = read_file(fd, buf);
	while (r_size)
	{
		if (is_end_of_func(buf, r_size))
		{
			backup[fd] = save_backup(buf, r_size);
			ret = make_ret(ret, buf);
			return (ret);
		}
		ret = make_ret(ret, buf);
		r_size = read_file(fd, buf);
	}
	return (ret);
}

int	is_end_of_func(char *buf, int r_size)
{
	return (ft_memchr(buf, '\n', r_size) || ft_memchr(buf, 0, r_size));
}