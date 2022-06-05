/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:52:29 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/04 19:04:33 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../libft/libft.h"
#include "../include/push_swap.h"

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