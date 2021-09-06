/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:32:40 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/23 13:30:21 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		key_process(int keycode, t_fdf *fdf)
{
	if (keycode == ESC)
	{
		finish_program(fdf);
		exit(0);
	}
	else
		control_keyboard(keycode, fdf);
	return (0);
}

static int		mouse_process(int keycode, int x, int y, t_fdf *fdf)
{
	if (x || y)
		;
	if (keycode == 4)
	{
		if (fdf->scale < INT_MAX)
			fdf->scale++;
	}
	else if (keycode == 5)
		if (fdf->scale > 1)
			fdf->scale--;
	return (1);
}

void			make_hook(t_fdf *fdf)
{
	mlx_hook(fdf->win, 4, 0, mouse_process, fdf);
	mlx_hook(fdf->win, 2, 1L << 0, key_process, fdf);
	mlx_loop_hook(fdf->mlx, draw, fdf);
}
