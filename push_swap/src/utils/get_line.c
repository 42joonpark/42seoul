/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 12:51:21 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/04 10:26:54 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_line2(char **line, char **data)
{
	char	*pos;

	pos = js_strchr(*data, '\n');
	if (pos)
	{
		*line = js_strndup(*data, pos - *data);
		free(*data);
		return (1);
	}
	else
	{
		*line = js_strndup(*data, js_strlen(*data));
		free(*data);
		return (0);
	}
}

int	get_line(int fd, char **line)
{
	char	*data;
	char	*buf;
	char	*tmp;
	int		bytes;

	buf = (char *)malloc(sizeof(char) * 2);
	if (buf == NULL)
		return (-1);
	data = js_strndup("", 0);
	bytes = read(fd, buf, 1);
	while (bytes > 0)
	{
		buf[bytes] = '\0';
		tmp = data;
		data = js_strjoin(data, buf);
		free(tmp);
		if (buf[0] == '\n')
			break ;
		bytes = read(fd, buf, 1);
	}
	free(buf);
	return (get_line2(line, &data));
}
