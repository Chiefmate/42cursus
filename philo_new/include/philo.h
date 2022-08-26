/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:24:32 by hyunhole          #+#    #+#             */
/*   Updated: 2022/08/15 20:24:32 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_arg {
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_each_must_eat;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*philo_time_flags;
	pthread_mutex_t	print;
	pthread_mutex_t	start_flag;
	pthread_mutex_t	finish_flag;
	int				num_finished_philo;
	int				is_finished;
}	t_arg;

typedef struct s_philo {
	t_arg		*argptr;
	pthread_t	tid;
	int			id;
	int			lfork;
	int			rfork;
	long long	last_eat_time;
	int			count_eat;
}	t_philo;

/* init.c */
int			ft_init_arg(t_arg *arg, int argc, char *argv[]);
int			ft_init_philoarr(t_philo **philo_arr, t_arg *arg);

/* simul.c */
int			ft_simul_philo(t_arg *arg, t_philo *philo_arr);

/* thread.c */
void		*ft_thread(void *argv);

/* thread_utils.c */
void		ft_wait_for_time(long long duration, t_arg *arg);
int			ft_philo_printf(t_arg *arg, int id, char *s);

/* utils.c */
int			ft_perror(int errno, char *s);
long long	ft_get_time(void);
int			ft_atoi(const char *s);

#endif