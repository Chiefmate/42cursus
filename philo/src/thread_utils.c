/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 10:50:44 by hyunhole          #+#    #+#             */
/*   Updated: 2022/08/23 18:03:28 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_wait_for_time(long long duration, t_arg *arg)
{
	long long	origin;
	long long	curr;

	origin = ft_get_time();
	while (!(arg->is_finished))
	{
		curr = ft_get_time();
		if (curr - origin >= duration)
			break ;
		usleep(10);
	}
	return ;
}

void	ft_wait_until_time(long long target, t_arg *arg)
{
	long long	curr;

	while (!(arg->is_finished))
	{
		curr = ft_get_time();
		if (curr >= target)
			break ;
		usleep(10);
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
	if (!arg->is_finished)
		printf("%lld %d %s\n", curr - arg->start_time, id + 1, s);
	pthread_mutex_unlock(&(arg->print));
	return (0);
}

int	ft_thread_check_if_dead(t_arg *arg, t_philo *philo)
{
	long long	curr;

	if (!(arg->is_finished))
	{
		curr = ft_get_time();
		if (curr == -1)
			return (-1);
		if (curr - philo->last_eat_time >= arg->time_to_die)
		{
			pthread_mutex_lock(&(arg->print));
			if (!(arg->is_finished))
				printf("%lld %d %s\n", curr - arg->start_time, \
						philo->id + 1, "died");
			arg->is_finished = 1;
			pthread_mutex_unlock(&(arg->print));
		}
	}
	return (0);
}
