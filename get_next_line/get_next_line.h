/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:53:40 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/16 18:39:37 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*join_ret_buf(char *ret, char *buf, ssize_t offset);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*get_backup(char *buf, ssize_t offset, ssize_t r_size);
char	*ft_strdup(const char *s);
ssize_t	get_offset(char *buf, ssize_t r_size);
int		is_lb(char *buf, ssize_t r_size);
char	*get_next_line(int fd);

#endif
