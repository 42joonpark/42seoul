/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:22:06 by joonpark          #+#    #+#             */
/*   Updated: 2021/10/09 20:53:19 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print(t_philo *philo, t_status status)
{
	sem_wait(philo->info->print_sem);
	printf("%ld ", get_time());
	printf("%d ", philo->idx + 1);
	if (status == EATING)
		printf("is eating\n");
	else if (status == SLEEPING)
		printf("is sleeping\n");
	else if (status == THINKING)
		printf("is thinking\n");
	else if (status == FORK)
		printf("has taken a fork\n");
	else if (status == DEAD)
		printf("is dead\n");
	sem_post(philo->info->print_sem);
}
