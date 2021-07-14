/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:07:58 by joonpark          #+#    #+#             */
/*   Updated: 2021/05/11 15:57:01 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		size;
	char	*ret;

	size = 0;
	while (str[size])
		++size;
	ret = (char *)str + size;
	while (size >= 0)
	{
		if ((unsigned char)*ret == (unsigned char)c)
			return (ret);
		--ret;
		--size;
	}
	return (NULL);
}
