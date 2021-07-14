/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:58:58 by joonpark          #+#    #+#             */
/*   Updated: 2021/05/11 15:52:29 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
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
