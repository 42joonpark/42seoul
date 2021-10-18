/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:57:14 by joonpark          #+#    #+#             */
/*   Updated: 2021/10/10 17:52:03 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	init_philo(t_info *info)
{
	int	idx;

	idx = 0;
	while (idx < info->num_of_philo)
	{
		info->philo[idx].idx = idx;
		info->philo[idx].last_eat = get_time();
		info->philo[idx].meals = 0;
		info->philo[idx].info = info;
		info->philo[idx].live = TRUE;
		++idx;
	}
	return (1);
}

static int	init_pointers(t_info *info)
{
	info->philo = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	if (info->philo == NULL)
		return (error("init_info(): failed to allocate philo.\n"));
	return (1);
}

static int	help(t_info *info)
{
	info->is_running = TRUE;
	info->is_all_eaten = FALSE;
	if (init_pointers(info) < 0)
		return (error("help(): failed to allocate.\n"));
	sem_unlink("/fork");
	sem_unlink("/print_sem");
	sem_unlink("/status_sem");
	sem_unlink("/dead_sem");
	sem_unlink("/eaten_sem");
	info->fork = sem_open("/fork", O_CREAT | O_EXCL, 0644, info->num_of_philo);
	info->print_sem = sem_open("/print_sem", O_CREAT | O_EXCL, 0644, 1);
	info->status_sem = sem_open("/status_sem", O_CREAT | O_EXCL, 0644, 1);
	info->dead_sem = sem_open("/dead_sem", O_CREAT | O_EXCL, 0644, 0);
	info->eaten_sem = sem_open("/eaten_sem", O_CREAT | O_EXCL, 0644, 0);
	init_philo(info);
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
		return (error("init_info(): time_to_[die, eat, sleep] must be"
				" >= 60ms.\n"));
	if (argc == 6)
	{
		info->must_eat = get_argument(argv[5]);
		if (info->must_eat <= 0)
			return (error("init_info(): must_eat <= 0.\n"));
	}
	else
		info->must_eat = -1;
	return (help(info));
}
