/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:17:56 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/30 15:17:56 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

typedef	struct	s_store
{
	int				fd;
	char			buf[BUFFER_SIZE];
	struct s_store	*next;
}				t_store;

char	*get_next_line(int fd);
int		empty_buf(int fd, char *buf, t_store *store);
t_store	*find_fd_store(int fd, t_store *store);
char	*make_ret(char *ret, char *buf, char *keep_fd, ssize_t read_size);
char	*concat_ret_buf(char *a, char *b, ssize_t c_size);

void	*ft_memchr(const void *buf, int c, size_t count);
size_t	ft_strnlen(char *str, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t n);

#endif