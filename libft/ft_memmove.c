/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:04:27 by joonpark          #+#    #+#             */
/*   Updated: 2021/05/11 15:53:20 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	t;
	char	*d;
	char	*s;

	if (!dst && !src)
		return (NULL);
	d = (char *)dst;
	s = (char *)src;
	if (s < d && d < s + n)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	else
	{
		t = 0;
		while (t < n)
		{
			d[t] = s[t];
			++t;
		}
	}
	return (dst);
}
