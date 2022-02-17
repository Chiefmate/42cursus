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

typedef enum	e_flag
{
	F_SHARP = 0, 
	F_SPACE, 
	F_PLUS, 
	F_MINUS, 
	F_ZERO, 
	F_MAX
}				t_flag;

typedef struct	s_info
{
	char	flag[F_MAX];
	int		width;
	int		precision;
	char	fspec;
}				t_info;

int		ft_printf(const char *fmt, ...);
int		ft_vdprintf(int fd, const char *fmt, va_list ap);

void	*ft_memset(void *b, int c, size_t n);
int		ft_putchar_fd(int fd, char c);
int		ft_putstr_fd(int fd, char *s, t_info info);
int		ft_putnbr_fd(int fd, int num, t_info info);
int		ft_puthex_fd(int fd, long long num, t_info info);

#endif