/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:54:47 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/03 16:43:33 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//  ft_strlen() 사용
char	*ft_strrchr(const char *s, int c)
{
	char	*ret;
	int		idx;

	ret = (void *)0;
	idx = ft_strlen(s);
	while (idx >= 0)
	{
		if (s[idx] == c)
		{
			ret = (char *)s + idx;
			break ;
		}
		idx--;
	}
	return (ret);
}
