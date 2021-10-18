/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:22:06 by joonpark          #+#    #+#             */
/*   Updated: 2021/10/07 14:24:32 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print(t_philo *philo, t_status status)
{
	pthread_mutex_lock(&philo->info->status);
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
	pthread_mutex_unlock(&philo->info->status);
}
