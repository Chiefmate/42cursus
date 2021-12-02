/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:44:31 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/02 16:44:31 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
	return ;
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cursor;
	t_list	*temp;

	temp = *lst;
	cursor = *lst;
	while (cursor)
	{
		temp = cursor;
		del(cursor->content);
		cursor = cursor->next;
		free(temp);
	}
	return ;
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*cursor;

	cursor = lst;
	while (cursor)
	{
		f(cursor->content);
		cursor = cursor->next;
	}
	return ;
}

//	ft_lstnew, ft_lstadd_back, ft_lstclear used
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*cursor_org;
	t_list	*temp;

	if (!lst || !f || !(ret = ft_lstnew(f(lst->content))))
		return ((void *)0);
	cursor_org = lst->next;
	if (!(ret = ft_lstnew(f(cursor_org->content))))
		return ((void *)0);
	while (cursor_org && ret)
	{
		if (!(temp = ft_lstnew(f(cursor_org->content))))
		{
			ft_lstclear(&ret, del);
			return ((void *)0);
		}
		ft_lstadd_back(&ret, temp);
		cursor_org = cursor_org->next;
	}
	return (ret);
}