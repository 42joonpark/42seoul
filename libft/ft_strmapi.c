/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 14:28:56 by joonpark          #+#    #+#             */
/*   Updated: 2021/05/11 16:17:17 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	length;
	size_t	idx;
	char	*ret;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	ret = (char *)malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	idx = 0;
	while (s[idx])
	{
		ret[idx] = f(idx, s[idx]);
		++idx;
	}
	ret[idx] = '\0';
	return (ret);
}
