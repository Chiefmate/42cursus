/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:06:46 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/03 16:39:52 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
