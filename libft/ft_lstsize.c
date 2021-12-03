/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:05:15 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/03 16:05:26 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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