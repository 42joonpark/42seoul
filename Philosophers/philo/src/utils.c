/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:45:00 by joonpark          #+#    #+#             */
/*   Updated: 2021/10/07 14:23:40 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>
#include <sys/time.h>

long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

int	js_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

int	error(char *msg)
{
	write(STDERR_FILENO, msg, js_strlen(msg));
	return (-1);
}

int	left(t_info *info, int idx)
{
	return ((idx + 1) % info->num_of_philo);
}

int	right(t_info *info, int idx)
{
	return ((idx + info->num_of_philo - 1) % info->num_of_philo);
}
