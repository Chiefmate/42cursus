/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:21:16 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/03 16:15:27 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

extern size_t	ft_strlen(const char *s);
extern int		ft_isalpha(int c);
extern int		ft_isdigit(int c);
extern void		*ft_memset(void *b, int c, size_t n);
extern void		*ft_memcpy(void *dst, const void *src, size_t n);
extern size_t	ft_strlcpy(char *dest, const char *src, size_t size);
extern char		*ft_substr(char const *s, unsigned int start, size_t len);
extern char		*ft_itoa(int n);
extern void		ft_putstr_fd(char *s, int fd);
extern t_list	*ft_lstnew(void *content);
extern void		ft_lstadd_back(t_list **lst, t_list *new);
extern t_list	*ft_lstlast(t_list *lst);
extern void		ft_lstclear(t_list **lst, void (*del)(void *));

#endif
