/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:07:17 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/03 16:07:29 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	ft_lstnew, ft_lstadd_back, ft_lstclear used
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*cursor_org;
	t_list	*temp;

	ret = ft_lstnew(f(lst->content));
	if (!lst || !f || !ret)
		return ((void *)0);
	cursor_org = lst->next;
	ret = ft_lstnew(f(cursor_org->content));
	if (!ret)
		return ((void *)0);
	while (cursor_org && ret)
	{
		temp = ft_lstnew(f(cursor_org->content));
		if (!temp)
		{
			ft_lstclear(&ret, del);
			return ((void *)0);
		}
		ft_lstadd_back(&ret, temp);
		cursor_org = cursor_org->next;
	}
	return (ret);
}