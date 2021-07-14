/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:50:45 by joonpark          #+#    #+#             */
/*   Updated: 2021/05/11 15:55:27 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		size;
	char	*ret;

	size = 0;
	while (str[size])
		++size;
	ret = (char *)str;
	while (size >= 0)
	{
		if ((unsigned char)*ret == (unsigned char)c)
			return (ret);
		--size;
		++ret;
	}
	return (NULL);
}
