/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 17:54:45 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/23 12:46:14 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	make_map_terminate(t_map *map, t_chead *header)
{
	int			y;

	y = 0;
	while (y < map->height)
	{
		if (map->arr[y])
			free(map->arr[y]);
		++y;
	}
	if (map->arr)
		free(map->arr);
	free_chead(header);
	return (-1);
}

int			make_map_arr(t_map *map, t_chead *header)
{
	int			y;
	int			x;
	t_coord		*p;

	if ((map->arr = (t_point **)malloc(sizeof(t_point *) * map->height)) < 0)
		return (-1);
	y = -1;
	p = header->head;
	while (++y < map->height)
	{
		if (!(map->arr[y] = (t_point *)malloc(sizeof(t_point) * map->width)))
			return (make_map_terminate(map, header));
		x = -1;
		while (++x < map->width)
		{
			map->arr[y][x].x = x;
			map->arr[y][x].y = y;
			map->arr[y][x].z = p->z;
			map->arr[y][x].color = p->color;
			map->z_min = ft_min(map->z_min, map->arr[y][x].z);
			map->z_max = ft_max(map->z_max, map->arr[y][x].z);
			p = p->next;
		}
	}
	return (free_chead(header));
}
