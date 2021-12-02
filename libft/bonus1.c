/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:41:46 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/02 16:41:46 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	creates a node
t_list	*ft_lstnew(void *content)
{
	t_list	*ret;

	if (!(ret = (t_list *)malloc(sizeof(t_list))))
		return ((void *)0);
	ret->content = content;
	ret->next = (void *)0;
	return (ret);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	*lst = new;
	(*lst)->next = temp;
	return ;
}

int	ft_lstsize(t_list *lst)
{
	int		ret;
	t_list	*cursor;

	cursor = lst;
	ret = 0;
	while (cursor->next)
	{
		ret++;
		cursor = cursor->next;
	}
	return (ret);
}

//	handled empty list
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ret;
	t_list	*cursor;

	ret = lst;
	cursor = lst;
	while (cursor)
	{
		ret = cursor;
		cursor = cursor->next;
	}
	return (ret);
}

//	ft_lstlast used
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (!last)
		*lst = new;
	last->next = new;
	return ;
}