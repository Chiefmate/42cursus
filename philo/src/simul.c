/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:34:18 by hyunhole          #+#    #+#             */
/*   Updated: 2022/08/16 15:34:18 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_simul_check_finish(t_arg *arg, t_philo *philo);
static int	ft_simul_check_if_dead(t_arg *arg, t_philo *philo_arr);
static void	ft_free_main_thread(t_arg *arg, t_philo *philo);

int	ft_simul_philo(t_arg *arg, t_philo *philo_arr)
{
	int	i;

	pthread_mutex_lock(&(arg->start_flag));
	i = 0;
	while (i < arg->num_philo)
	{
		philo_arr[i].last_eat_time = ft_get_time();
		if (pthread_create(&(philo_arr[i].tid), NULL, \
					ft_thread, &(philo_arr[i])))
			return (1);
		i++;
	}
	pthread_mutex_unlock(&(arg->start_flag));
	ft_simul_check_finish(arg, philo_arr);
	i = 0;
	while (i < arg->num_philo)
		pthread_join(philo_arr[i++].tid, NULL);
	ft_free_main_thread(arg, philo_arr);
	return (0);
}

static void	ft_simul_check_finish(t_arg *arg, t_philo *philo_arr)
{
	while (1)
	{
		if (check_if_finished(arg))
			break ;
		if ((arg->num_each_must_eat != 0) && \
				(arg->num_philo <= arg->num_finished_philo))
		{
			pthread_mutex_lock(&(arg->finish_flag));
			arg->is_finished = 1;
			pthread_mutex_unlock(&(arg->finish_flag));
			break ;
		}
		if (ft_simul_check_if_dead(arg, philo_arr))
		{
			pthread_mutex_lock(&(arg->finish_flag));
			arg->is_finished = 1;
			pthread_mutex_unlock(&(arg->finish_flag));
			break ;
		}
		usleep(1000);
	}
	return ;
}

static int	ft_simul_check_if_dead(t_arg *arg, t_philo *philo_arr)
{
	long long	curr;
	int			i;

	i = -1;
	while (++i < arg->num_philo)
	{
		if (check_if_finished(arg))
			break ;
		curr = ft_get_time();
		if (curr == -1)
			return (-1);
		pthread_mutex_lock(&(arg->philo_time_flags[i]));
		if (curr - philo_arr[i].last_eat_time >= arg->time_to_die)
		{
			pthread_mutex_unlock(&(arg->philo_time_flags[i]));
			flag_is_finished_true(arg);
			ft_simul_printf_died(arg, philo_arr[i].id);
			break ;
		}
		pthread_mutex_unlock(&(arg->philo_time_flags[i]));
	}
	return (0);
}

static void	ft_free_main_thread(t_arg *arg, t_philo *philo_arr)
{
	int	i;

	i = -1;
	while (++i < arg->num_philo)
	{
		pthread_mutex_destroy(&(arg->forks[i]));
		pthread_mutex_destroy(&(arg->philo_time_flags[i]));
	}
	free(philo_arr);
	free(arg->forks);
	free(arg->philo_time_flags);
	pthread_mutex_destroy(&(arg->print));
	pthread_mutex_destroy(&(arg->start_flag));
	pthread_mutex_destroy(&(arg->finish_flag));
	return ;
}
