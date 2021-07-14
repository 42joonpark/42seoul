/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:15:58 by joonpark          #+#    #+#             */
/*   Updated: 2021/05/20 19:45:11 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*cur;
	size_t			cnt;

	cnt = 0;
	cur = (unsigned char *)b;
	while (cnt < len)
	{
		*cur = c;
		++cur;
		++cnt;
	}
	return (b);
}

unsigned char	*ft_strdup(const unsigned char *str)
{
	int				size;
	unsigned char	*ret;

	size = -1;
	while (str[++size])
		;
	ret = (unsigned char *)malloc(sizeof(unsigned char) * (size + 1));
	if (!ret)
		return (NULL);
	size = -1;
	while (str[++size])
		ret[size] = str[size];
	ret[size] = '\0';
	return (ret);
}

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
