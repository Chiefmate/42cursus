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

	i = 0;
	while (i < arg->num_philo)
	{
		philo_arr[i].last_eat_time = ft_get_time();
		if (pthread_create(&(philo_arr[i].tid), NULL, ft_thread, &(philo_arr[i])))
			return (1);
		i++;
	}
	ft_simul_check_finish(arg, philo);
	i = 0;
	while (i < arg->num_philo)
		pthread_join(philo[i++].tid, NULL);
	ft_free_main_thread(arg, philo);
	return (0);
}

static void	ft_simul_check_finish(t_arg *arg, t_philo *philo_arr)
{
	long long	curr_time;

	while (!(arg->is_finished))
	{
		if ((arg->num_each_must_eat != 0) && (arg->num_philo <= arg->num_finished_philo))
		{
			arg->is_finished = 1;
			break ;
		}
		if (ft_simul_check_if_dead(arg, philo_arr))
		{
			arg->is_finished = 1;
			break ;
		}
	}
	return ;
}

static int	ft_simul_check_if_dead(t_arg *arg, t_philo *philo_arr)
{
	long long	curr;
	int			i;

	pthread_mutex_lock(&(arg->print));
	i = -1;
	while (++i < arg->num_philo)
	{
		curr = ft_get_time();
		if (now == -1)
			return (-1);
		if (curr - philo_arr[i].last_eat_time >= arg->time_to_die)
		{
			printf("%lld %d %s\n", curr - arg->start_time, id + 1, "died");
			arg->is_finished = 1;
			break ;
		}
	}
	pthread_mutex_unlock(&(arg->print));
	return (0);
}


static void	ft_free_main_thread(t_arg *arg, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < arg->num_philo)
		pthread_mutex_destroy(&(arg->forks[i]));
	free(philo);
	free(arg->forks);
	pthread_mutex_destroy(&(arg->print));
	return ;
}