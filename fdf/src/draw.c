/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:08:29 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/23 13:15:36 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	my_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		dst = fdf->data_addr + (y * fdf->size_line +
								x * (fdf->bits_per_pixel / 8));
		*dst = color;
		*(++dst) = color >> 8;
		*(++dst) = color >> 16;
	}
}

static void	draw_background(t_fdf *fdf)
{
	int			y;
	int			x;

	y = -1;
	while (++y < WINDOW_HEIGHT)
	{
		x = -1;
		while (++x < WINDOW_WIDTH)
			my_pixel_put(fdf, x, y, BG_COLOR);
	}
}

static void	draw_line(t_fdf *fdf, t_point s, t_point e, t_point cur)
{
	t_point		d;
	int			ss[2];
	int			err[2];

	d.x = abs(e.x - s.x);
	d.y = -abs(e.y - s.y);
	ss[0] = s.x < e.x ? 1 : -1;
	ss[1] = s.y < e.y ? 1 : -1;
	err[0] = d.x + d.y;
	while (cur.x != e.x || cur.y != e.y)
	{
		my_pixel_put(fdf, cur.x + fdf->camera->x_pos,
				cur.y + fdf->camera->y_pos, get_current_color(d, s, e, cur));
		err[1] = 2 * err[0];
		if (err[1] >= d.y)
		{
			err[0] += d.y;
			cur.x += ss[0];
		}
		if (err[1] <= d.x)
		{
			err[0] += d.x;
			cur.y += ss[1];
		}
	}
}

int			draw(t_fdf *fdf)
{
	int		y;
	int		x;
	t_point	temp;

	draw_background(fdf);
	y = -1;
	while (++y < fdf->map->height)
	{
		x = -1;
		while (++x < fdf->map->width)
		{
			temp = get_new_point(x, y, fdf);
			if (y - 1 >= 0)
				draw_line(fdf, conversion(temp, fdf),
						conversion(get_new_point(x, y - 1, fdf), fdf),
						conversion(temp, fdf));
			if (x - 1 >= 0)
				draw_line(fdf, conversion(temp, fdf),
						conversion(get_new_point(x - 1, y, fdf), fdf),
						conversion(temp, fdf));
		}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	return (1);
}
