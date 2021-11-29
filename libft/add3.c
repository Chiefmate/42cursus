/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:42:53 by hyunhole          #+#    #+#             */
/*   Updated: 2021/11/29 18:42:53 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic.h"

//	ft_itoa, ft_putstr_fd used
void	ft_putnbr_fd(int n, int fd)
{
	char	*str;

	str = ft_itoa(n);
	ft_putstr_fd(str, fd);
	return ;
}