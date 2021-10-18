/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:19:16 by joonpark          #+#    #+#             */
/*   Updated: 2021/10/07 14:10:54 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_running(t_info *info)
{
	int	idx;

	idx = 0;
	while (idx < info->num_of_philo)
	{
		if (info->philo[idx].live == TRUE)
			return (1);
		++idx;
	}
	return (0);
}

static void	eating(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	pick_up(info, philo->idx);
	if (info->is_running == FALSE || philo->live == FALSE)
		return ;
	print(philo, FORK);
	print(philo, FORK);
	print(philo, EATING);
	philo->last_eat = get_time();
	eat(philo);
	put_down(info, philo->idx);
	if (info->is_running == FALSE)
		return ;
	if (info->must_eat != -1 && philo->meals >= info->must_eat)
		philo->live = FALSE;
	if (philo->live == FALSE)
		return ;
}

static void	sleeping(t_philo *philo)
{
	t_info	*info;
	long	time;

	print(philo, SLEEPING);
	info = philo->info;
	time = get_time();
	while (get_time() - time <= info->time_to_sleep && philo->live
		&& info->is_running == TRUE)
		usleep(100);
}

void	*monitor_start(void *arg)
{
	t_info	*info;
	t_philo	*philo;

	philo = (t_philo *)arg;
	info = philo->info;
	while (info->is_running == TRUE)
	{
		eating(philo);
		if (info->is_running == FALSE || philo->live == FALSE)
			break ;
		sleeping(philo);
		if (info->is_running == FALSE || philo->live == FALSE)
			break ;
		print(philo, THINKING);
		if (info->is_running == FALSE || philo->live == FALSE)
			break ;
	}
	return (NULL);
}

void	*thread_start(void *arg)
{
	t_info	*info;
	t_philo	*philo;

	philo = (t_philo *)arg;
	info = philo->info;
	while (philo->info->is_running == TRUE)
	{
		if (philo->live == FALSE)
		{
			print(philo, DEAD);
			if (check_running(info) == 0)
				info->is_running = FALSE;
			break ;
		}
		if (get_time() - philo->last_eat >= info->time_to_die)
		{
			print(philo, DEAD);
			info->is_running = FALSE;
			break ;
		}
		usleep(100);
	}
	return (NULL);
}
