/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:54:20 by hyunhole          #+#    #+#             */
/*   Updated: 2022/08/26 17:02:15 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* returns 1 if arg->is_finished == 1
 *         0 if arg->is_finished == 0
 * a function for mutexes
 */
int	check_if_finished(t_arg *arg)
{
	pthread_mutex_lock(&(arg->finish_flag));
	if (arg->is_finished)
	{
		pthread_mutex_unlock(&(arg->finish_flag));
		return (1);
	}
	pthread_mutex_unlock(&(arg->finish_flag));
	return (0);
}

void	flag_is_finished_true(t_arg *arg)
{
	pthread_mutex_lock(&(arg->finish_flag));
	if (!(arg->is_finished))
		arg->is_finished = 1;
	pthread_mutex_unlock(&(arg->finish_flag));
	return ;
}

int	ft_simul_printf_died(t_arg *arg, int id)
{
	long long	curr;

	curr = ft_get_time();
	if (curr == -1)
		return (-1);
	pthread_mutex_lock(&(arg->print));
	usleep(1000);
	printf("%lld %d %s\n", curr - arg->start_time, \
		id + 1, "died");
	pthread_mutex_unlock(&(arg->print));
	return (0);
}
