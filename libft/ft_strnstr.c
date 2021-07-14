/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:04:33 by joonpark          #+#    #+#             */
/*   Updated: 2021/05/11 15:57:22 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		check(const char *big, const char *little)
{
	while (*big && *little)
	{
		if (*big != *little)
			return (0);
		++big;
		++little;
	}
	return (*little == '\0');
}

char				*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*s;
	size_t	length;
	size_t	size;

	length = ft_strlen(little);
	s = (char *)big;
	if (length == 0)
		return (s);
	if (len == 0)
		return (NULL);
	size = 0;
	while (*big && size <= (int)len - length)
	{
		if (*big == *little)
		{
			if (check(big, little))
			{
				s = (char *)big;
				return (s);
			}
		}
		++size;
		++big;
	}
	return (NULL);
}
