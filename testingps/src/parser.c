/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:41:16 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/05 16:25:13 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
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

long long	atoi_with_check(char *s, t_stack *a, char **splitarr)
{
	char		flag;
	long long	n;
	t_node		*curr;

	flag = 0;
	n = 0;
	if (*s == '-')
	{
		flag = 1;
		s++;
	}
	if (ft_strlen(s) > 10 || ft_strlen(s) == 0)
		ft_error_with_clear(a, splitarr);
	while (ft_isdigit(*s))
	{
		n *= 10;
		n += *s++ - '0';
	}
	if (flag == 1)
		n *= -1;
	if (*s != '\0' || n < INT_MIN || n > INT_MAX)
		ft_error_with_clear(a, splitarr);
	curr = a->head;
	while (curr)
	{
		if (curr->data == n)
			ft_error_with_clear(a, splitarr);
		curr = curr->next;
	}
	return (n);
}

void	ft_destroy_split(char **splitarr)
{
	int	i;

	i = -1;
	while (splitarr[++i])
		free(splitarr[i]);
	free(splitarr);
	return ;
}