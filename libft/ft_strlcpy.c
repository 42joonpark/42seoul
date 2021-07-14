/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 08:40:21 by joonpark          #+#    #+#             */
/*   Updated: 2021/05/11 15:54:59 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	idx;
	size_t	ret;

	if (!dst || !src)
		return (0);
	ret = 0;
	while (src[ret])
		++ret;
	idx = 0;
	if (size > 0)
	{
		while (src[idx] && idx < (size - 1))
		{
			dst[idx] = src[idx];
			++idx;
		}
		dst[idx] = '\0';
	}
	return (ret);
}
