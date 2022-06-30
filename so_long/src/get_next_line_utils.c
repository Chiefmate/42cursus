/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:40:48 by hyunhole          #+#    #+#             */
/*   Updated: 2022/02/07 16:26:59 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//	ft_memchr used
size_t	ft_strnlen(char *str, size_t n)
{
	char	*part;

	part = ft_memchr(str, 0, n);
	if (!part)
		return (n);
	else
		return (part - str);
}
