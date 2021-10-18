/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:42:58 by joonpark          #+#    #+#             */
/*   Updated: 2021/10/10 19:00:57 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	free_info(t_info *info)
{
	int	idx;

	idx = 0;
	while (idx < info->num_of_philo)
	{
		pthread_mutex_destroy(&info->state_mutex[idx]);
		++idx;
	}
	pthread_mutex_destroy(&info->status);
	pthread_mutex_destroy(&info->hungry_mutex);
	if (info->state_mutex != NULL)
		free(info->state_mutex);
	if (info->philo != NULL)
		free(info->philo);
	if (info->state != NULL)
		free(info->state);
	if (info->l_hungry != NULL)
		free(info->l_hungry);
	if (info->r_hungry != NULL)
		free(info->r_hungry);
}

static int	run(t_info *info)
{
	int	idx;

	idx = -1;
	while (++idx < info->num_of_philo)
	{
		pthread_create(&info->philo[idx].thread, NULL, thread_start,
			&info->philo[idx]);
		pthread_create(&info->philo[idx].monitor, NULL, monitor_start,
			&info->philo[idx]);
	}
	idx = -1;
	while (++idx < info->num_of_philo)
	{
		pthread_join(info->philo[idx].thread, NULL);
		pthread_join(info->philo[idx].monitor, NULL);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc < 5 || argc > 6)
		return (error("<Usage>: num_of_philo / time_to_die / "
				"time_to_eat / time_to_sleep / [must_eat]\n"));
	if (init_info(&info, argc, argv) < 0)
	{
		error("main(): init_info failed.\n");
		return (EXIT_FAILURE);
	}
	run(&info);
	free_info(&info);
	return (0);
}
