/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fatal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:08:42 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/23 13:17:07 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <errno.h>

void		free_results(char **results)
{
	int		idx;

	if (results)
	{
		idx = 0;
		while (results[idx])
		{
			free(results[idx]);
			++idx;
		}
		if (results)
		{
			free(results);
			results = NULL;
		}
	}
}

int			free_chead(t_chead *header)
{
	header->tail = header->head;
	while (header->tail != NULL)
	{
		header->head = header->tail;
		header->tail = header->head->next;
		free(header->head);
	}
	return (1);
}

void		free_map(t_map *map)
{
	int			y;

	if (map->arr)
	{
		y = -1;
		while (++y < map->height)
			if (map->arr[y])
				free(map->arr[y]);
		free(map->arr);
	}
}

int			read_map_terminate(char *msg, char *s, char **res, t_chead *header)
{
	int			idx;

	if (s && *s)
		free(s);
	idx = 0;
	free_results(res);
	free_chead(header);
	if (errno == 0)
		ft_putstr_fd(msg, 2);
	else
		perror(msg);
	return (-1);
}
