/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:25:21 by joonpark          #+#    #+#             */
/*   Updated: 2021/05/11 16:00:14 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	len;

	len = count * size;
	ret = (void *)malloc(len);
	if (!ret)
		return (NULL);
	ft_memset(ret, 0, len);
	return (ret);
}
