/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:02:01 by hyunhole          #+#    #+#             */
/*   Updated: 2022/03/04 15:48:45 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int					ft_printf(const char *fmt, ...);
int					ft_vdprintf(int fd, const char *fmt, va_list ap);
void				*ft_memset(void *b, int c, size_t n);
int					ft_putchar_fd(int fd, char c);
int					ft_putstr_fd(int fd, char *s);
int					ft_putnbr_fd(int fd, int num);
int					ft_putunbr_fd(int fd, unsigned int num);
unsigned int		ft_puthexsml_fd(int fd, unsigned int num);
unsigned int		ft_puthexbig_fd(int fd, unsigned int num);
unsigned long long	ft_putadd_fd(int fd, unsigned long long num);

#endif
