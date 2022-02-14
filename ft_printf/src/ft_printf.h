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

#endif