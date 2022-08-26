/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 10:50:44 by hyunhole          #+#    #+#             */
/*   Updated: 2022/08/26 15:56:31 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_wait_for_time(long long duration, t_arg *arg)
{
	long long	origin;
	long long	curr;

	origin = ft_get_time();
	while (1)
	{
		pthread_mutex_lock(&(arg->finish_flag));
		if (arg->is_finished)
		{
			pthread_mutex_unlock(&(arg->finish_flag));
			break ;
		}
		pthread_mutex_unlock(&(arg->finish_flag));
		curr = ft_get_time();
		if (curr - origin >= duration)
			break ;
		usleep(500);
	}
	return ;
}

int	ft_philo_printf(t_arg *arg, int id, char *s)
{
	long long	curr;

	curr = ft_get_time();
	if (curr == -1)
		return (-1);
	pthread_mutex_lock(&(arg->print));
	pthread_mutex_lock(&(arg->finish_flag));
	if (!arg->is_finished)
		printf("%lld %d %s\n", curr - arg->start_time, id + 1, s);
	pthread_mutex_unlock(&(arg->finish_flag));
	pthread_mutex_unlock(&(arg->print));
	return (0);
}
