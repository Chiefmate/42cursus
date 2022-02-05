/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:38:16 by hyunhole          #+#    #+#             */
/*   Updated: 2022/02/05 14:38:16 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

void	*ft_memchr(const void *buf, int c, size_t count);
size_t	ft_strnlen(char *str, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t n);
char	*ft_strdup(const char *s);

char	*make_ret(char *a, char *b, ssize_t c_size);
int		init_buf(int fd, char *buf, char *keep_fd);
char	*check_ret(char *ret, char *buf, char *keep_fd, ssize_t r_size);
char	*solve(int fd, char *ret, char *buf, char *keep_fd);
char	*get_next_line(int fd);

#endif