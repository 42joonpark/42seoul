/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:46:05 by joonpark          #+#    #+#             */
/*   Updated: 2021/05/11 16:01:02 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	return (a < b ? a : b);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	idx;
	size_t	length;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	if (length < start)
		ret = (char *)malloc(sizeof(char) * 1);
	else
		ret = (char *)malloc(sizeof(char) * (ft_min(length - start, len) + 1));
	if (!ret)
		return (NULL);
	idx = 0;
	while (start + idx <= length && idx < len)
	{
		ret[idx] = s[start + idx];
		++idx;
	}
	ret[idx] = '\0';
	return (ret);
}
