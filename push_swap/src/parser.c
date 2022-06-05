/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:41:16 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/04 19:11:02 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

/* parse input and assigns the values into inarr
 *  returns 0   if error
 *          1   if successful
 */
int parse_input(t_stack *a, int argc, char *argv[])
{
    int     i;
    int     j;
    int     temp;
    char    **splitarr;

    i = 0;
    while (++i < argc)
    {
        splitarr = ft_split(argv[i], ' ');
        if (!splitarr)
            ft_error_with_clear(a, splitarr);
        j = -1;
        while (splitarr[++j])
        {
            temp = atoi_with_check(splitarr[j], a, splitarr);
            push_bottom(a, temp);
        }
        ft_destroy_split(splitarr);
    }
    return (1);
}
