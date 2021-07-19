/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:15:51 by joonpark          #+#    #+#             */
/*   Updated: 2021/07/17 13:33:27 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	cat_buffer(unsigned char **str, unsigned char buffer[])
{
	int				idx_1;
	int				idx_2;
	unsigned char	*temp;
	unsigned char	*del;

	idx_1 = 0;
	idx_2 = 0;
	while ((*str)[idx_1])
		++idx_1;
	while (buffer[idx_2])
		++idx_2;
	if (!(temp = (unsigned char *)malloc(sizeof(unsigned char) *\
					(idx_1 + idx_2 + 1))))
		return (-1);
	idx_1 = -1;
	idx_2 = -1;
	while ((*str)[++idx_1])
		temp[idx_1] = (*str)[idx_1];
	while (buffer[++idx_2])
		temp[idx_1 + idx_2] = buffer[idx_2];
	temp[idx_1 + idx_2] = '\0';
	del = *str;
	*str = temp;
	free(del);
	return (0);
}

static int	make_result(unsigned char **str, char **line,
							unsigned char *c)
{
	unsigned char	*cur;
	unsigned char	*start;

	start = *str;
	cur = *str;
	while (*cur != '\n' && *cur != '\0')
		++cur;
	*c = *cur;
	if (*cur == '\n')
		*cur++ = '\0';
	if ((*line = (char *)ft_strdup(start)) == NULL)
		return (-1);
	if ((*str = ft_strdup(cur)) == NULL)
		return (-1);
	free(start);
	return (0);
}

static int	free_current(unsigned char *strs[],\
							unsigned char *buf, int fd, int ret)
{
	if (buf)
		free(buf);
	if (strs[fd])
	{
		free(strs[fd]);
		strs[fd] = NULL;
	}
	return (ret);
}

static int	middle_function(unsigned char *strs[],\
							unsigned char *buffer, int read_cnt, int fd)
{
	buffer[read_cnt] = '\0';
	if (strs[fd] == NULL)
		if ((strs[fd] = ft_strdup((unsigned char *)"")) == NULL)
			return (-1);
	if (cat_buffer(&strs[fd], buffer) == -1)
		return (-1);
	if (ft_strchr(buffer, '\n') || read_cnt == 0)
		return (0);
	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static unsigned char	*strs[OPEN_MAX];
	int						read_cnt;
	int						res;
	unsigned char			*buffer;
	unsigned char			c;

	if (fd < 0 || OPEN_MAX < fd || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	if ((buffer = (unsigned char *)malloc(sizeof(unsigned char) *\
					(BUFFER_SIZE + 1))) == NULL)
		return (free_current(strs, buffer, fd, -1));
	while ((read_cnt = read(fd, buffer, BUFFER_SIZE)) >= 0)
	{
		res = middle_function(strs, buffer, read_cnt, fd);
		if (res == -1)
			return (free_current(strs, buffer, fd, -1));
		else if (res == 0)
			break ;
	}
	if (read_cnt < 0 || make_result(&strs[fd], line, &c) == -1)
		return (free_current(strs, buffer, fd, -1));
	if (c == '\0' && read_cnt == 0)
		return (free_current(strs, buffer, fd, 0));
	free(buffer);
	return (1);
}
