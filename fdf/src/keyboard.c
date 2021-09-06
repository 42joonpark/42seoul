/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:26:55 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/23 13:00:41 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		make_parallel(t_fdf *fdf)
{
	fdf->is_isometric = -fdf->is_isometric;
	fdf->camera->x_axis = 0;
	fdf->camera->y_axis = 0;
	fdf->camera->z_axis = 0;
	return (1);
}

static void		check_vector(int keycode, t_fdf *fdf)
{
	if (keycode == LEFT)
		fdf->camera->x_pos -= 10;
	else if (keycode == RIGHT)
		fdf->camera->x_pos += 10;
	else if (keycode == DOWN)
		fdf->camera->y_pos += 10;
	else if (keycode == UP)
		fdf->camera->y_pos -= 10;
	else if (keycode == ENG_P)
		make_parallel(fdf);
	else if (keycode == COMMA)
	{
		if (fdf->camera->s_speed > 1)
			fdf->camera->s_speed--;
	}
	else if (keycode == DOT)
		fdf->camera->s_speed++;
}

void			control_keyboard(int keycode, t_fdf *fdf)
{
	if (keycode == ENG_Q)
		fdf->camera->x_axis += fdf->camera->s_speed;
	else if (keycode == ENG_W)
		fdf->camera->y_axis += fdf->camera->s_speed;
	else if (keycode == ENG_E)
		fdf->camera->z_axis += fdf->camera->s_speed;
	else if (keycode == ENG_A)
		fdf->camera->x_axis -= fdf->camera->s_speed;
	else if (keycode == ENG_S)
		fdf->camera->y_axis -= fdf->camera->s_speed;
	else if (keycode == ENG_D)
		fdf->camera->z_axis -= fdf->camera->s_speed;
	else
		check_vector(keycode, fdf);
}
