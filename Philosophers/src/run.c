/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:03:29 by joonpark          #+#    #+#             */
/*   Updated: 2021/10/10 18:14:53 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <signal.h>

static void	*check_all_eaten(void *arg)
{
	t_info	*info;
	int		idx;

	idx = 0;
	info = (t_info *)arg;
	while (idx < info->num_of_philo)
	{
		sem_wait(info->eaten_sem);
		if (info->is_running == FALSE)
			return (NULL);
		++idx;
	}
	info->is_all_eaten = TRUE;
	return (NULL);
}

static void	*check_all_dead(void *arg)
{
	t_info	*info;

	info = (t_info *)arg;
	sem_wait(info->dead_sem);
	info->is_running = FALSE;
	return (NULL);
}

int	run(t_info *info)
{
	int		idx;

	if (pthread_create(&info->eat_thread, NULL, check_all_eaten, info))
		return (error("run(): failed to create eat thread.\n"));
	if (pthread_create(&info->die_thread, NULL, check_all_dead, info))
		return (error("run(): failed ot create die thread.\n"));
	idx = -1;
	while (++idx < info->num_of_philo)
	{
		info->philo[idx].pid = fork();
		if (info->philo[idx].pid < 0)
			return (error("run(): failed to fork.\n"));
		else if (info->philo[idx].pid == 0)
		{
			process(&info->philo[idx]);
			return (1);
		}
	}
	while (info->is_running == TRUE && info->is_all_eaten == FALSE)
		usleep(100);
	idx = -1;
	while (++idx < info->num_of_philo)
		kill(info->philo[idx].pid, SIGTERM);
	return (2);
}
