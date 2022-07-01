/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:17:14 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/30 15:17:14 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*ret;
	char			*buf;
	static t_store	*store;
	ssize_t			read_size;
	t_store			*store_fd;

	if (fd < 0)
		return (0);
	ret = NULL;
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (0);
	ft_memset(buf, 0, BUFFER_SIZE);

	store_fd = find_fd_store(fd, store);
	read_size = empty_buf(fd, buf, store_fd);
	while (read_size > 0)
	{
		ret = make_ret(ret, buf, store_fd->buf, read_size);
		if (!ret || !buf[0])
			break ;
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	if (!read_size)
		ft_memset(store_fd->buf, 0, BUFFER_SIZE);
	if (read_size < 0 && ret)
	{
		free(ret);
		ret = NULL;
	}
	free(buf);
	buf = NULL;
	return (ret);
}

/* 
 *	copy the string in the existing fd buffer to the main function buffer,
 *	and clear out the fd buffer
 */
int	empty_buf(int fd, char *buf, t_store *store)
{
	ssize_t	read_size;
	size_t	store_buf_len;
	int		i;
	t_store	*temp;

	temp = store;
	while (temp && temp->fd != fd)
		temp = temp->next;
	store_buf_len = ft_strlen(store->buf);
	if (!temp)
	{
		temp->next = (t_store *)malloc(sizeof(t_store));
		if (!temp->next)
			return (-1);
		temp->next->fd = fd;
		ft_memset(temp->next->buf, 0, BUFFER_SIZE);
		temp->next->next = NULL;
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	else
	{
		read_size = ft_strnlen(temp->buf, BUFFER_SIZE);
		ft_memcpy(buf, temp->buf, read_size);
		ft_memset(temp->buf, 0, BUFFER_SIZE);
	}
	return (read_size);
}

/*
 *	find the t_store var with the required fd
 *	if not found, allocate t_store var and attach to the existing t_store list
 */
t_store	*find_fd_store(int fd, t_store *store)
{
	t_store	*temp;
	t_store	*newfd_store;

	temp = store;
	while (temp && temp->fd != fd)
		temp = temp->next;
	if (temp->fd == fd)
		return (temp);
	newfd_store = (t_store *)malloc(sizeof(t_store));
	if (!newfd_store)
		return (NULL);
	newfd_store->fd = fd;
	ft_memset(newfd_store->buf, 0, BUFFER_SIZE);
	temp = store;
	while (temp && temp->next != NULL)
		temp = temp->next;
	temp->next = newfd_store;
	return (newfd_store);
}

/*
 *	Make a line to return, concatenating the existing buffer and the newly read string
 *	exit if the read buffer reads '\n' or EOF
 */
char	*make_ret(char *ret, char *buf, char *keep_fd, ssize_t read_size)
{
	char	*offset;

	offset = ft_memchr(buf, '\n', read_size);
	if (offset)
	{
		ret = concat_ret_buf(ret, buf, offset - buf + 1);
		if (ret == -1)
			return (NULL);
		ft_memset(keep_fd, 0, BUFFER_SIZE);
		if (read_size - (offset - buf) >= 1)
			ft_memcpy(keep_fd, offset + 1, read_size - (offset - buf) - 1);
		ft_memset(buf, 0, BUFFER_SIZE);
		return (ret);
	}
	ret = concat_ret_buf(ret, buf, read_size);
	return (ret);
}

/*
 *	concatenate a and b, which is of length of c_size
 */
char	*concat_ret_buf(char *a, char *b, ssize_t c_size)
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