/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:34:47 by joonpark          #+#    #+#             */
/*   Updated: 2021/10/10 18:07:32 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	eating(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	sem_wait(info->status_sem);
	sem_wait(philo->info->fork);
	print(philo, FORK);
	sem_wait(philo->info->fork);
	print(philo, FORK);
	sem_post(info->status_sem);
	print(philo, EATING);
	philo->last_eat = get_time();
	while (get_time() - philo->last_eat <= philo->info->time_to_eat
		&& philo->live == TRUE)
		usleep(1000);
	philo->meals++;
	sem_post(philo->info->fork);
	sem_post(philo->info->fork);
}

static void	sleeping(t_philo *philo)
{
	t_info	*info;
	long	start_time;

	start_time = get_time();
	info = philo->info;
	print(philo, SLEEPING);
	while (get_time() - start_time < info->time_to_sleep
		&& philo->live == TRUE && info->is_running == TRUE)
		usleep(100);
}

void	*monitor_start(void *arg)
{
	t_info	*info;
	t_philo	*philo;

	philo = (t_philo *)arg;
	info = philo->info;
	philo->last_eat = get_time();
	while (philo->live == TRUE && info->is_running == TRUE)
	{
		eating(philo);
		if (info->must_eat != -1 && philo->meals >= info->must_eat)
		{
			philo->live = FALSE;
			sem_post(info->eaten_sem);
		}
		if (info->is_running == FALSE || philo->live == FALSE)
			break ;
		sleeping(philo);
		if (info->is_running == FALSE || philo->live == FALSE)
			break ;
		print(philo, THINKING);
	}
	return (NULL);
}

int	process(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	if (pthread_create(&philo->monitor, NULL, monitor_start, philo))
		return (EXIT_FAILURE);
	while (info->is_running == TRUE && philo->live == TRUE)
	{
		if (get_time() - philo->last_eat >= info->time_to_die)
		{
			philo->live = FALSE;
			print(philo, DEAD);
			sem_post(info->dead_sem);
		}
		usleep(100);
	}
	return (1);
}
