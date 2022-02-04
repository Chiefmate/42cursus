/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:40:53 by hyunhole          #+#    #+#             */
/*   Updated: 2022/01/16 15:52:33 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
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

size_t	ft_strlen(const char *s);
void	make_keep(char keep[], char *buf, ssize_t c_size);
char	*make_ret(char *a, char *b, ssize_t c_size);
char	*get_next_line(int fd);

#endif
