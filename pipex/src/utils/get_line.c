/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:36:00 by joonpark          #+#    #+#             */
/*   Updated: 2021/08/04 13:57:38 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	get_line2(char **line, char **data)
{
	char	*pos;

	pos = ft_strchr(*data, '\n');
	if (pos)
	{
		*line = ft_strndup(*data, pos - *data);
		*data += pos - *data + 1;
		return (1);
	}
	else
	{
		*line = ft_strndup(*data, ft_strlen(*data));
		return (0);
	}
}

int	get_line(int fd, char **line)
{
	char	*data;
	char	*buf;
	char	*tmp;
	int		bytes;

	buf = (char *) malloc(sizeof(char) * 2);
	if (buf == NULL)
		return (-1);
	data = ft_strndup("", 0);
	bytes = read(fd, buf, 1);
	while (bytes > 0)
	{
		buf[bytes] = '\0';
		tmp = data;
		data = ft_strjoin(data, buf);
		free(tmp);
		if (buf[0] == '\n')
			break ;
		bytes = read(fd, buf, 1);
	}
	free(buf);
	return (get_line2(line, &data));
}
