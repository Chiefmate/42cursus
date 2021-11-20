/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 00:05:34 by hyunhole          #+#    #+#             */
/*   Updated: 2021/11/17 00:05:34 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isalpha(int c)
{
    return (((unsigned)c | 32) - 'a' < 26);
}

int ft_isdigit(int c)
{
    return ((unsigned)c - '0' < 10);
}

int ft_isalnum(int c)
{
    return (ft_isalpha(c) || ft_isdigit(c));
}

int ft_isascii(int c)
{
    if (0 <= c && c <= 127)
        return (1);
    else
        return (0);
}

int ft_isprint(int c)
{
    return ((unsigned)c - 32 < 95);
}