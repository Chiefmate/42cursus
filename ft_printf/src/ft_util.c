/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:30:52 by hyunhole          #+#    #+#             */
/*   Updated: 2022/02/12 12:30:52 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(int fd, char c, t_info info)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putnbr_fd(int fd, char c, t_info info)
{

}
