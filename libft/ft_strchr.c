/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:54:31 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/03 15:54:39 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*ret;
	int		idx;

	ret = (void *)0;
	idx = 0;
	while (s[idx])
	{
		if (s[idx] == c)
		{
			ret = (char *)s + idx;
			break ;
		}
		idx++;
	}
	return (ret);
}