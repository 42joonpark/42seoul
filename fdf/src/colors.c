/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:39:54 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/23 13:58:07 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	get_percentage(int s, int e, int c)
{
	double	base;
	double	top;

	base = e - s;
	top = c - s;
	if (base == 0)
		return (1.0);
	return (top / base);
}

static int		get_depend_on_percentage(int s, int e, double percentage)
{
	return (int)((1 - percentage) * s + percentage * e);
}

int				get_default_color(t_fdf *fdf, int z)
{
	double	percentage;

	percentage = get_percentage(fdf->map->z_min, fdf->map->z_max, z);
	if (percentage < 0.2)
		return (ONE_OF_FIVE);
	else if (percentage < 0.4)
		return (TWO_OF_FIVE);
	else if (percentage < 0.6)
		return (THREE_OF_FIVE);
	else if (percentage < 0.8)
		return (FOUR_OF_FIVE);
	else
		return (FIVE_OF_FIVE);
}

int				get_current_color(t_point diff, t_point s, t_point e,
									t_point cur)
{
	int		red;
	int		blue;
	int		green;
	double	percentage;

	if (s.color == e.color)
		return (s.color);
	if (diff.y < 0)
		diff.y *= -1;
	if (diff.x > diff.y)
		percentage = get_percentage(s.x, e.x, cur.x);
	else
		percentage = get_percentage(s.y, e.y, cur.y);
	red = get_depend_on_percentage(s.color & 0xff,
			e.color & 0xff, percentage);
	green = get_depend_on_percentage(s.color >> 8 & 0xff,
			e.color >> 8 & 0xff, percentage);
	blue = get_depend_on_percentage(s.color >> 16 & 0xff,
			e.color >> 16 & 0xff, percentage);
	return (red | green << 8 | blue << 16);
}
