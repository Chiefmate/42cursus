/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:03:23 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/10 12:07:45 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	ft_itoa, ft_putstr_fd used
void	ft_putnbr_fd(int n, int fd)
{
	char	*str;

	str = ft_itoa(n);
	ft_putstr_fd(str, fd);
	free(str);
	return ;
}
