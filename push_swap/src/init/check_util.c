/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 13:23:50 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/01 20:41:23 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_strs_lenfth(char ***strs)
{
	int	size;
	int	idx;
	int	i;

	size = 0;
	idx = 0;
	while (strs[idx])
	{
		i = 0;
		while (strs[idx][i])
		{
			++i;
			++size;
		}
		++idx;
	}
	return (size);
}

void	free_strs(char ***strs)
{
	int	idx;
	int	i;

	if (strs != NULL)
	{
		idx = -1;
		while (strs[++idx] != NULL)
		{
			i = 0;
			while (strs[idx][i] != NULL)
				free(strs[idx][i++]);
			free(strs[idx]);
		}
		free(strs);
	}
}
