/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:34:21 by hyunhole          #+#    #+#             */
/*   Updated: 2022/08/16 15:34:21 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_init_arg_mutex(t_arg *arg);

int	ft_init_arg(t_arg *arg, int argc, char *argv[])
{
	arg->num_philo = ft_atoi(argv[1]);
	arg->time_to_die = ft_atoi(argv[2]);
	arg->time_to_eat = ft_atoi(argv[3]);
	arg->time_to_sleep = ft_atoi(argv[4]);
	arg->num_each_must_eat = 0;
	arg->start_time = ft_get_time();
	arg->num_finished_philo = 0;
	arg->is_finished = 0;
	if (arg->num_philo <= 0 || arg->time_to_die < 0 || arg->time_to_eat < 0 \
			|| arg->time_to_sleep < 0)
		return (1);
	if (argc == 6)
	{
		arg->num_each_must_eat = ft_atoi(argv[5]);
		if (arg->num_each_must_eat <= 0)
			return (1);
	}
	if (ft_init_arg_mutex(arg))
		return (1);
	return (0);
}

static int	ft_init_arg_mutex(t_arg *arg)
{
	int			i;
	long long	curr_time;

	if (pthread_mutex_init(&(arg->print), NULL))
		return (1);
	if (pthread_mutex_init(&(arg->start_flag), NULL))
		return (1);
	arg->forks = malloc(sizeof(pthread_mutex_t) * arg->num_philo);
	if (!(arg->forks))
		return (1);
	arg->fork_avail_times = malloc(sizeof(long long) * arg->num_philo);
	if (!(arg->fork_avail_times))
		return (1);
	curr_time = ft_get_time();
	i = 0;
	while (i < arg->num_philo)
	{
		arg->fork_avail_times[i] = curr_time;
		if (pthread_mutex_init(&(arg->forks[i]), NULL))
			return (1);
		i++;
	}
	return (0);
}

int	ft_init_philoarr(t_philo **philo_arr, t_arg *arg)
{
	int	i;

	i = 0;
	*philo_arr = malloc(sizeof(t_philo) * arg->num_philo);
	if (!(*philo_arr))
		return (1);
	while (i < arg->num_philo)
	{
		(*philo_arr)[i].argptr = arg;
		(*philo_arr)[i].id = i;
		(*philo_arr)[i].lfork = i;
		(*philo_arr)[i].rfork = (i + 1) % arg->num_philo;
		(*philo_arr)[i].last_eat_time = ft_get_time();
		(*philo_arr)[i].count_eat = 0;
		i++;
	}
	return (0);
}
