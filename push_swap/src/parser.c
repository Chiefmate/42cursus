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
int parse_input(t_stack *a, int argc, char *argv[], int *cnt)
{
    int     i;
    int     j;
    int     temp;
    char    **splitarr;

    if (!is_valid_input(argc, argv))
        return (0);
    i = -1;
    while (++i < argc)
    {
        if (!ft_strchr(argv[i], ' '))
        {
            if (!ft_atoi_sp(argv[i], &temp))
                ft_error();
            push_top(a, temp);
            cnt++;
        }
        else
        {
            splitarr = ft_split(argv[i], ' ');            
            j = -1;
            while (splitarr[++j])
            {
                if (!ft_atoi_sp(splitarr[j], &temp))
                    ft_error();
                push_top(a, temp);
                cnt++;
            }
        }
    }
    return (1);
}

/*
 *  allowed characters: '+', '-', number, space
 */
int is_valid_input(int argc, char *argv[])
{
    int i;
    int j;
    
    i = -1;
    while (++i < argc)
    {
        j = -1;
        while (++j < (int)ft_strlen(argv[i]))
        {
            if (!ft_isdigit(argv[i][j]) && argv[i][j] != '+' \
            &&  argv[i][j] != '+' && argv[i][j] != ' ')
                return (0);
        }    
    }
    return (1);
}