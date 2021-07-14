/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 11:28:03 by joonpark          #+#    #+#             */
/*   Updated: 2021/05/11 15:55:15 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dst_len;
	size_t		remain;
	char		*d;
	const char	*s;

	d = dst;
	remain = size;
	while (remain-- > 0 && *d)
		++d;
	dst_len = d - dst;
	remain = size - dst_len;
	if (remain == 0)
		return (dst_len + ft_strlen(src));
	s = src;
	while (*s)
	{
		if (remain > 1)
		{
			*d++ = *s;
			--remain;
		}
		++s;
	}
	*d = '\0';
	return (dst_len + (s - src));
}
