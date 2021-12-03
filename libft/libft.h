/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:21:16 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/03 12:04:11 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBFT_H__
# define __LIBFT_H__
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

extern size_t ft_strlen(const char *s);
extern int ft_isdigit(int c);
extern void *ft_memset(void *b, int c, size_t n);
extern size_t ft_strlcpy(char *dest, const char *src, size_t size);
extern char *ft_itoa(int n);
extern void ft_putstr_fd(char *s, int fd);
extern t_list *ft_lstnew(void *content);
extern void ft_lstadd_back(t_list **lst, t_list *new);

#endif
