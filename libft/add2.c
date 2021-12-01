/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:33:34 by hyunhole          #+#    #+#             */
/*   Updated: 2021/11/29 18:33:34 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	ft_strlen used
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned char	idx;

	if (!(ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return ((void *)0);
	idx = -1;
	while (++idx < ft_strlen(s))
		ret[idx] = f(idx, s[idx]);
	ret[idx] = '\0';
	return (ret);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char			*tempptr;
	unsigned int	idx;
	
	idx = 0;
	tempptr = s;
	while (*tempptr)
	{
		f(idx, tempptr);
		idx++;
		tempptr++;
	}
	return ;
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return ;
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	return ;
}

//	ft_putstr_fd used
void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
	return ;
}