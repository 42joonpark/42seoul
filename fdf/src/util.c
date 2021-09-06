/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:13:44 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/23 13:49:26 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		get_new_point(int x, int y, t_fdf *fdf)
{
	t_point				new_point;

	new_point.x = x;
	new_point.y = y;
	new_point.z = fdf->map->arr[y][x].z;
	new_point.color = fdf->map->arr[y][x].color;
	if (new_point.color == 0x000000)
		new_point.color = get_default_color(fdf, new_point.z);
	return (new_point);
}

int			ft_min(int a, int b)
{
	return (a > b ? b : a);
}

int			ft_max(int a, int b)
{
	return (a > b ? a : b);
}

double		to_radian(double a)
{
	return ((M_PI / 180) * a);
}
