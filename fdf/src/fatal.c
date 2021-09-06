/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 20:17:37 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/23 13:30:28 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <errno.h>

int			terminate(char *s)
{
	if (errno == 0)
		ft_putstr_fd(s, 2);
	else
		perror(s);
	return (-1);
}

void		fatal(char *s)
{
	if (errno == 0)
		ft_putstr_fd(s, 2);
	else
		perror(s);
	exit(1);
}

void		finish_program(t_fdf *fdf)
{
	int			y;

	y = -1;
	while (++y < fdf->map->height)
		free(fdf->map->arr[y]);
	free(fdf->map->arr);
	free(fdf->map);
	free(fdf->camera);
	mlx_destroy_window(fdf->mlx, fdf->win);
}
