/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:42:58 by joonpark          #+#    #+#             */
/*   Updated: 2021/10/10 18:18:21 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	free_info(t_info *info)
{
	if (info->is_running == TRUE)
		sem_post(info->dead_sem);
	if (info->is_all_eaten == FALSE)
		sem_post(info->eaten_sem);
	sem_close(info->fork);
	sem_close(info->print_sem);
	sem_close(info->status_sem);
	sem_close(info->dead_sem);
	sem_close(info->eaten_sem);
	sem_unlink("/fork");
	sem_unlink("/print_sem");
	sem_unlink("/status_sem");
	sem_unlink("/dead_sem");
	sem_unlink("/eaten_sem");
	if (info->philo)
		free (info->philo);
}

int	main(int argc, char *argv[])
{
	t_info	info;
	int		res;

	if (argc < 5 || argc > 6)
		return (error("<Usage>: num_of_philo / time_to_die / "
				"time_to_eat / time_to_sleep / [must_eat]\n"));
	if (init_info(&info, argc, argv) < 0)
	{
		free_info(&info);
		error("main(): init_info failed.\n");
		return (EXIT_FAILURE);
	}
	res = run(&info);
	if (res == 0)
	{
		free_info(&info);
		error("main(): run failed.\n");
		return (EXIT_FAILURE);
	}
	else if (res == 2)
	{
		free_info(&info);
	}
	return (EXIT_SUCCESS);
}
