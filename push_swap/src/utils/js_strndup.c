/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   js_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:06:24 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/04 10:51:01 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*js_strndup(char *str, int size)
{
	char	*ret;
	int		idx;

	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	idx = 0;
	while (str[idx] && idx < size)
	{
		ret[idx] = str[idx];
		++idx;
	}
	ret[idx] = '\0';
	return (ret);
}
