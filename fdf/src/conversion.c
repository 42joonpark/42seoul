/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:59:04 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/23 13:26:28 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_z(t_point *point, t_fdf *fdf)
{
	int		y;
	int		x;

	x = point->x;
	y = point->y;
	point->x = x * cos(to_radian(fdf->camera->z_axis)) -
		y * sin(to_radian(fdf->camera->z_axis));
	point->y = x * sin(to_radian(fdf->camera->z_axis)) +
		y * cos(to_radian(fdf->camera->z_axis));
}

static void	rotate_x(t_point *point, t_fdf *fdf)
{
	int		y;
	int		z;

	y = point->y;
	z = point->z;
	point->y = y * cos(to_radian(fdf->camera->x_axis)) -
		z * sin(to_radian(fdf->camera->x_axis));
	point->z = y * sin(to_radian(fdf->camera->x_axis)) +
		z * cos(to_radian(fdf->camera->x_axis));
}

static void	rotate_y(t_point *point, t_fdf *fdf)
{
	int		z;
	int		x;

	z = point->z;
	x = point->x;
	point->z = z * cos(to_radian(fdf->camera->y_axis)) -
		x * sin(to_radian(fdf->camera->y_axis));
	point->x = z * sin(to_radian(fdf->camera->y_axis)) +
		x * cos(to_radian(fdf->camera->y_axis));
}

t_point		conversion(t_point point, t_fdf *fdf)
{
	point.x *= fdf->scale;
	point.y *= fdf->scale;
	point.z *= fdf->scale;
	rotate_x(&point, fdf);
	rotate_y(&point, fdf);
	rotate_z(&point, fdf);
	point.x += WINDOW_WIDTH / 2;
	if (fdf->is_isometric == ISOMETRIC)
		iso(&point);
	return (point);
}
