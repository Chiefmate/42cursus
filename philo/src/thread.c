/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:35:18 by hyunhole          #+#    #+#             */
/*   Updated: 2022/08/16 15:35:18 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_thread_even_id(t_arg *arg, t_philo *philo);
static int	ft_philo_eat_even_id(t_arg *arg, t_philo *philo);
static void	*ft_thread_odd_id(t_arg *arg, t_philo *philo);
static int	ft_philo_eat_odd_id(t_arg *arg, t_philo *philo);

void	*ft_thread(void *argv)
{
	t_arg	*arg;
	t_philo	*philo;

	philo = argv;
	arg = philo->argptr;
	if (philo->id % 2)
		ft_thread_odd_id(arg, philo);
	else
		ft_thread_even_id(arg, philo);
	return (0);
}

/* thread function for philosophers with even number id: 0, 2, 4, ... */
static void	*ft_thread_even_id(t_arg *arg, t_philo *philo)
{
	while (!(arg->is_finished))
	{
		if (ft_philo_eat_even_id(arg, philo))
		{
			if (arg->num_each_must_eat != 0 && \
					arg->num_each_must_eat <= philo->count_eat)
			{
				arg->num_finished_philo += 1;
				break ;
			}
			ft_philo_printf(arg, philo->id, "is sleeping");
			ft_wait_for_time((long long)arg->time_to_sleep, arg);
			ft_philo_printf(arg, philo->id, "is thinking");
			usleep(50);
		}
		ft_thread_check_if_dead(arg, philo);
	}
	return (0);
}

/* thread function for philosophers with odd number id: 1, 3, 5, ... */
static void	*ft_thread_odd_id(t_arg *arg, t_philo *philo)
{
	usleep(500);
	while (!(arg->is_finished))
	{		
		if (ft_philo_eat_odd_id(arg, philo))
		{
			if (arg->num_each_must_eat != 0 && \
					arg->num_each_must_eat <= philo->count_eat)
			{
				arg->num_finished_philo += 1;
				break ;
			}
			ft_philo_printf(arg, philo->id, "is sleeping");
			ft_wait_for_time((long long)arg->time_to_sleep, arg);
			ft_philo_printf(arg, philo->id, "is thinking");
			usleep(50);
		}
		ft_thread_check_if_dead(arg, philo);
	}
	return (0);
}

/* eat function for philosophers with even number id: 0, 2, 4, ... */
static int	ft_philo_eat_even_id(t_arg *arg, t_philo *philo)
{
	int	have_eaten;

	have_eaten = 0;
	pthread_mutex_lock(&(arg->forks[philo->lfork]));
	ft_philo_printf(arg, philo->id, "has taken a fork");
	if (arg->num_philo == 1)
		ft_wait_for_time((long long)arg->time_to_die, arg);
	if (arg->num_philo != 1)
	{
		pthread_mutex_lock(&(arg->forks[philo->rfork]));
		ft_philo_printf(arg, philo->id, "has taken a fork");
		ft_philo_printf(arg, philo->id, "is eating");
		philo->last_eat_time = ft_get_time();
		philo->count_eat += 1;
		have_eaten = 1;
		ft_wait_for_time((long long)arg->time_to_eat, arg);
		pthread_mutex_unlock(&(arg->forks[philo->rfork]));
	}
	pthread_mutex_unlock(&(arg->forks[philo->lfork]));
	return (have_eaten);
}

/* eat function for philosophers with odd number id: 1, 3, 5, ... */
static int	ft_philo_eat_odd_id(t_arg *arg, t_philo *philo)
{
	int	have_eaten;

	have_eaten = 0;
	pthread_mutex_lock(&(arg->forks[philo->rfork]));
	ft_philo_printf(arg, philo->id, "has taken a fork");
	if (arg->num_philo != 1)
	{
		pthread_mutex_lock(&(arg->forks[philo->lfork]));
		ft_philo_printf(arg, philo->id, "has taken a fork");
		ft_philo_printf(arg, philo->id, "is eating");
		philo->last_eat_time = ft_get_time();
		philo->count_eat += 1;
		have_eaten = 1;
		ft_wait_for_time((long long)arg->time_to_eat, arg);
		pthread_mutex_unlock(&(arg->forks[philo->lfork]));
	}
	pthread_mutex_unlock(&(arg->forks[philo->rfork]));
	return (have_eaten);
}
