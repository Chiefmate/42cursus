/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:00:45 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/03 12:15:02 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t count)
{
	unsigned char   *ptr;
	unsigned char   *ret;
	size_t		  idx;

	ptr = (unsigned char *)buf;
	ret = (void *)0;
	idx = 0;
	while (*ptr && idx < count)
	{
		if (*ptr == c)
		{
			ret = ptr;
			break ;
		}
		count++;
		ptr++;
	}
	return (ret);
}

int ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	size_t		  idx;
	unsigned char   *p1;
	unsigned char   *p2;

	p1 = (unsigned char *)buf1;
	p2 = (unsigned char *)buf2;
	idx = 0;
	while (idx < count && p1[idx] == p2[idx])
		idx++;
	return (p1[idx] - p2[idx]);
}

//  ft_memset used
void	*calloc(size_t num, size_t size)
{
	void	*ret;

	ret = malloc(num * size);
	ft_memset(ret, 0, num * size);
	return (ret);
}

//  ft_strlen used
char	*strdup(const char *s)
{
	char	*ret;
	size_t  idx;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (ret == (void *)0)
		return (ret);
	idx = 0;
	while (idx < ft_strlen(s))
	{
		ret[idx] = s[idx];
		idx++;
	}
	ret[idx] = '\0';
	return (ret);
}
