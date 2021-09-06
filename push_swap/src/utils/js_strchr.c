/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   js_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:09:03 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/04 10:48:21 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*js_strchr(char *str, char c)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] == c)
			return (str + idx);
		++idx;
	}
	if (str[idx] == c)
		return (str + idx);
	return (NULL);
}
