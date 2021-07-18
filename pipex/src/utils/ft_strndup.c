/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:46:35 by joonpark          #+#    #+#             */
/*   Updated: 2021/07/17 18:32:28 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <stdio.h>
char	*ft_strndup(const char *str, int n)
{
	char	*ret;
	int		idx;

	ret = (char *)malloc(sizeof(char) * (n + 1));
	if (ret == NULL)
		return (NULL);
	idx = 0;
	while (str[idx] && idx < n)
	{
		ret[idx] = str[idx];
		++idx;
	}
	ret[idx] = '\0';
	return (ret);
}
