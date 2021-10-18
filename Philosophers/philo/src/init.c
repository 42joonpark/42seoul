/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:57:14 by joonpark          #+#    #+#             */
/*   Updated: 2021/10/10 18:59:01 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	init_rest(t_info *info)
{
	int	idx;

	info->state = (int *)malloc(sizeof(int) * info->num_of_philo);
	if (info->state == NULL)
		return (error("init_state(): failed to allocate state.\n"));
	info->l_hungry = (int *)malloc(sizeof(int) * info->num_of_philo);
	if (info->l_hungry == NULL)
		return (error("init_state(): failed to allocate l_hungry.\n"));
	info->r_hungry = (int *)malloc(sizeof(int) * info->num_of_philo);
	if (info->r_hungry == NULL)
		return (error("init_state(): failed to allocate r_hungry.\n"));
	idx = 0;
	while (idx < info->num_of_philo)
	{
		info->state[idx] = THINKING;
		info->l_hungry[idx] = FALSE;
		info->r_hungry[idx] = FALSE;
		++idx;
	}
	return (1);
}

static int	init_self(t_info *info)
{
	int	idx;

	info->state_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* info->num_of_philo);
	if (info->state_mutex == NULL)
		return (error("init_self(): failed to allocate self.\n"));
	idx = 0;
	while (idx < info->num_of_philo)
	{
		pthread_mutex_init(&info->state_mutex[idx], NULL);
		++idx;
	}
	return (1);
}

static int	init_philo(t_info *info)
{
	int	idx;

	idx = 0;
	while (idx < info->num_of_philo)
	{
		info->philo[idx].N = info->num_of_philo;
		info->philo[idx].idx = idx;
		info->philo[idx].last_eat = get_time();
		info->philo[idx].meals = 0;
		info->philo[idx].info = info;
		info->philo[idx].live = TRUE;
		++idx;
	}
	return (1);
}

static int	help(t_info *info)
{
	info->is_running = TRUE;
	pthread_mutex_init(&info->status, NULL);
	pthread_mutex_init(&info->hungry_mutex, NULL);
	if (init_self(info) < 0)
		return (error("init_info(): failed to init self.\n"));
	info->philo = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	if (info->philo == NULL)
		return (error("init_info(): failed to allocate philo.\n"));
	if (init_rest(info) < 0)
		return (error("help(): init_rest() failed.\n"));
	return (1);
}

int	init_info(t_info *info, int argc, char *argv[])
{
	info->num_of_philo = get_argument(argv[1]);
	if (info->num_of_philo < 0)
		return (error("init_info(): number of philosophers < 0.\n"));
	info->time_to_die = get_argument(argv[2]);
	info->time_to_eat = get_argument(argv[3]);
	info->time_to_sleep = get_argument(argv[4]);
	if (info->time_to_die < 60 || info->time_to_eat < 60
		|| info->time_to_sleep < 60)
		return (error("init_info(): time_to_[die, eat, sleep] must be >= 60ms.\n"));
	if (argc == 6)
	{
		info->must_eat = get_argument(argv[5]);
		if (info->must_eat <= 0)
			return (error("init_info(): must_eat <= 0.\n"));
	}
	else
		info->must_eat = -1;
	help(info);
	return (init_philo(info));
}
