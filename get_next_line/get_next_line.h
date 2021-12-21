/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:53:40 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/21 16:02:51 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*join_ret_buf(char *ret, char *buf, ssize_t offset);
size_t	ft_datalen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t n);
char	*ft_strdup(const char *s);
ssize_t	get_offset(char *buf, ssize_t r_size);
char	*update_backup(char *backup, char *buf, ssize_t r_size, ssize_t offset);
int		is_lb(char *buf, ssize_t r_size);
char	*get_next_line(int fd);

#endif
