/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:02:01 by hyunhole          #+#    #+#             */
/*   Updated: 2022/02/11 14:02:01 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *fmt, ...);
int		ft_vdprintf(int fd, const char *fmt, va_list ap);
void	*ft_memset(void *b, int c, size_t n);
int		ft_putchar_fd(int fd, char c);
int		ft_putstr_fd(int fd, char *s);
int		ft_putnbr_fd(int fd, int num);
int		ft_puthexsml_fd(int fd, long long num);
int		ft_puthexbig_fd(int fd, long long num);

#endif