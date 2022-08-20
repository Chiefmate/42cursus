/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:28:02 by hyunhole          #+#    #+#             */
/*   Updated: 2022/08/15 20:28:02 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_arg	arg;
	t_philo	*philo_arr;
	int		ret;

	if (argc != 5 && argc != 6)
		return (ft_perror(1, "argc error"));
	memset(&arg, 0, sizeof(t_arg));
	ret = ft_init_arg(&arg, argc, argv);
	if (ret)
		return (ft_perror(ret, "arg init error"));
	ret = ft_init_philoarr(&philo_arr, &arg);
	if (ret)
		return (ft_perror(ret, "philo init error"));
	ret = ft_simul_philo(&arg, philo_arr);
	if (ret)
		return (ft_perror(ret, "philo simul error"));
	return (0);
}