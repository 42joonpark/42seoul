/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 14:26:38 by joonpark          #+#    #+#             */
/*   Updated: 2021/05/11 16:16:55 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_count(long long n)
{
	size_t	count;

	if (n < 0)
		n *= -1;
	count = 0;
	while (n >= 0)
	{
		++count;
		n /= 10;
		if (n == 0)
			break ;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	size_t		len;
	size_t		idx;
	char		*ret;
	int			minus;
	long long	nb;

	minus = n < 0 ? 1 : 0;
	len = get_count(n) + minus;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	nb = n;
	if (nb < 0)
		nb *= -1;
	idx = 0;
	if (minus)
		ret[idx] = '-';
	while (idx + minus < len)
	{
		ret[len - idx - 1] = (nb % 10) + '0';
		nb /= 10;
		++idx;
	}
	ret[idx + minus] = '\0';
	return (ret);
}
