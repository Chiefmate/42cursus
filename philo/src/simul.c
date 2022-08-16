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
	ft_free_thread(arg, philo);
	return (0);
}

static void	ft_simul_check_finish(t_arg *arg, t_philo *philo)
{

}

void	*ft_thread(void *argv)
{
	t_arg	*arg;
	t_philo	*philo_arr;

	philo_arr = argv;
	arg = philo_arr->argptr;
	if (philo_arr->id % 2)
		
}

ft_free_thread