/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:15:51 by joonpark          #+#    #+#             */
/*   Updated: 2021/05/20 18:02:04 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

unsigned char	*ft_strchr(const unsigned char *str, int c)
{
	unsigned char	*ret;

	ret = (unsigned char *)str;
	while (*ret)
	{
		if (*ret == c)
			return (ret);
		++ret;
	}
	return (NULL);
}

int				cat_buffer(unsigned char **str, unsigned char buffer[])
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

int				make_result(unsigned char **str, char **line,
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

int				free_current(unsigned char *strs[], int fd, int ret)
{
	if (strs[fd])
	{
		free(strs[fd]);
		strs[fd] = NULL;
	}
	return (ret);
}

int				get_next_line(int fd, char **line)
{
	static unsigned char	*strs[OPEN_MAX];
	int						read_cnt;
	unsigned char			buffer[BUFFER_SIZE + 1];
	unsigned char			c;

	if (fd < 0 || OPEN_MAX <= fd || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	while ((read_cnt = read(fd, buffer, BUFFER_SIZE)) >= 0)
	{
		buffer[read_cnt] = '\0';
		if (strs[fd] == NULL)
			if ((strs[fd] = ft_strdup((unsigned char *)"")) == NULL)
				return (free_current(strs, fd, -1));
		if (cat_buffer(&strs[fd], buffer) == -1)
			return (free_current(strs, fd, -1));
		if (ft_strchr(buffer, '\n') || read_cnt == 0)
			break ;
	}
	if (read_cnt < 0 || make_result(&strs[fd], line, &c) == -1)
		return (free_current(strs, fd, -1));
	if (c == '\0' && read_cnt == 0)
		return (free_current(strs, fd, 0));
	return (1);
}
