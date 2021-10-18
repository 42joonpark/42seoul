/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:52:03 by joonpark          #+#    #+#             */
/*   Updated: 2021/10/07 14:36:44 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	pick_up(t_info *info, int idx)
{
	t_philo	*philo;

	philo = &info->philo[idx];
	pthread_mutex_lock(&info->state_mutex[idx]);
	info->state[idx] = HUNGRY;
	pthread_mutex_unlock(&info->state_mutex[idx]);
	test(info, idx);
	while (info->state[idx] != EATING && info->is_running == TRUE
		&& philo->live == TRUE)
		usleep(100);
	if (info->is_running == FALSE || philo->live == FALSE)
		return ;
	pthread_mutex_lock(&info->hungry_mutex);
	info->r_hungry[left(info, idx)] = FALSE;
	info->l_hungry[right(info, idx)] = FALSE;
	pthread_mutex_unlock(&info->hungry_mutex);
}

void	put_down(t_info *info, int idx)
{
	pthread_mutex_lock(&info->state_mutex[idx]);
	info->state[idx] = SLEEPING;
	pthread_mutex_unlock(&info->state_mutex[idx]);
	test(info, left(info, idx));
	if (info->state[left(info, idx)] == HUNGRY)
	{
		pthread_mutex_lock(&info->hungry_mutex);
		info->l_hungry[idx] = TRUE;
		pthread_mutex_unlock(&info->hungry_mutex);
	}
	test(info, right(info, idx));
	if (info->state[right(info, idx)] == HUNGRY)
	{
		pthread_mutex_lock(&info->hungry_mutex);
		info->r_hungry[idx] = TRUE;
		pthread_mutex_unlock(&info->hungry_mutex);
	}
}

void	test(t_info *info, int idx)
{
	pthread_mutex_lock(&info->state_mutex[idx]);
	if (info->state[right(info, idx)] != EATING
		&& info->state[idx] == HUNGRY
		&& info->state[left(info, idx)] != EATING
		&& info->l_hungry[idx] == FALSE && info->r_hungry[idx] == FALSE
		&& left(info, idx) != idx && right(info, idx) != idx)
	{
		info->state[idx] = EATING;
	}
	pthread_mutex_unlock(&info->state_mutex[idx]);
}

void	eat(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	philo->meals++;
	while (info->is_running == TRUE
		&& get_time() - philo->last_eat < info->time_to_eat)
	{
		usleep(100);
	}
}
