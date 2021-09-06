/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 19:54:46 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/23 12:45:45 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

static t_map		*map_init(void)
{
	t_map		*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	map->width = 0;
	map->height = 0;
	map->z_min = INT_MAX;
	map->z_max = INT_MIN;
	map->arr = NULL;
	return (map);
}

static t_camera		*camera_init(void)
{
	t_camera	*camera;

	if (!(camera = (t_camera *)malloc(sizeof(t_camera))))
		fatal(CAMERA_INIT_ERROR);
	camera->x_axis = 0;
	camera->y_axis = 0;
	camera->z_axis = 0;
	camera->s_speed = 5;
	camera->x_pos = 0;
	camera->y_pos = 0;
	return (camera);
}

static void			ft_mlx_init(t_fdf *fdf, t_map *map)
{
	if (!(fdf->mlx = mlx_init()))
	{
		free_map(map);
		fatal(MLX_INIT_ERROR);
	}
	if (!(fdf->win = mlx_new_window(fdf->mlx,
					WINDOW_WIDTH, WINDOW_HEIGHT, "fdf")))
	{
		free_map(map);
		fatal(MLX_NEW_WINDOW_ERROR);
	}
	fdf->data_addr = NULL;
	fdf->bits_per_pixel = 0;
	fdf->size_line = 0;
	fdf->endian = 0;
	fdf->img = mlx_new_image(fdf->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	fdf->data_addr = mlx_get_data_addr(fdf->img,
			&fdf->bits_per_pixel, &fdf->size_line, &fdf->endian);
	fdf->scale = ft_min((3 * WINDOW_WIDTH) / (7 * map->width),
			(3 * WINDOW_HEIGHT) / (7 * map->height));
	if (fdf->scale == 0)
		fdf->scale = 1;
	fdf->is_isometric = ISOMETRIC;
	fdf->map = map;
	fdf->camera = camera_init();
}

void				fdf_init(t_fdf *fdf, const char *file_name)
{
	t_map		*map;
	int			fd;

	if (!(map = map_init()))
		fatal(MAP_INIT_ERROR);
	if ((fd = open(file_name, O_RDONLY)) < 0)
	{
		free_map(map);
		fatal(MAP_OPEN_ERROR);
	}
	if (read_map(fd, map) < 0)
	{
		close(fd);
		free_map(map);
		fatal(MAP_CREAT_ERROR);
	}
	close(fd);
	ft_mlx_init(fdf, map);
}
