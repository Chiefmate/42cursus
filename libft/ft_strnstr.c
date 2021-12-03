/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:55:35 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/03 15:55:48 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//ft_strlen() 사용
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*ret;
	size_t	idx;
	size_t	temp;

	if (*little == '\0')
		return ((char *)big);
	ret = (void *)0;
	idx = 0;
	while (idx < len)
	{
		temp = 0;
		while (big[temp] == little[temp])
			temp++;
		if (temp && little[temp] == '\0')
		{
			ret = (char *)big + 1 - temp;
			break ;
		}
		idx++;
	}
	return (ret);
}