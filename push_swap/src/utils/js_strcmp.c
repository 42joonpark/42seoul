/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   js_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:28:39 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/03 13:30:09 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	js_strcmp(const char *s1, const char *s2)
{
	int	idx;

	idx = 0;
	while (s1[idx] && s2[idx])
	{
		if (s1[idx] != s2[idx])
			return (1);
		++idx;
	}
	if (s1[idx] == s2[idx])
		return (0);
	else
		return (1);
}
