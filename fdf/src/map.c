/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 19:57:26 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/23 13:16:36 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coord			*get_new_coord(char *s)
{
	t_coord		*ret;

	if (!(ret = (t_coord *)malloc(sizeof(t_coord))))
		return (NULL);
	ret->z = ft_atoi(s);
	ret->color = get_color(s);
	ret->next = NULL;
	return (ret);
}

static int				parse_line(char **result, t_chead *header)
{
	int				width;
	t_coord			*new_coord;

	width = -1;
	if (*result)
		width = 0;
	while (*result)
	{
		if (!(new_coord = get_new_coord(*result++)))
			return (terminate(NEW_COORD_ERROR));
		if (!header->tail)
		{
			header->head = new_coord;
			header->tail = new_coord;
		}
		else
		{
			header->tail->next = new_coord;
			header->tail = new_coord;
		}
		width++;
	}
	return (width);
}

int						read_map(int fd, t_map *map)
{
	t_chead			header;
	char			*line;
	char			**result;
	int				width;

	header.head = NULL;
	header.tail = NULL;
	while (get_next_line(fd, &line))
	{
		result = ft_split(line, ' ');
		if ((width = parse_line(result, &header)) < 0)
			return (read_map_terminate(READ_MAP_ERROR, line, result, &header));
		if (map->width == 0)
			map->width = width;
		if (map->width != width)
			return (read_map_terminate(WRONG_LENGTH, line, result, &header));
		map->height++;
		free_results(result);
		free(line);
	}
	free(line);
	return (make_map_arr(map, &header));
}
