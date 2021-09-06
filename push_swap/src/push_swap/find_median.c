/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 10:17:40 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/02 14:50:17 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_median(int *pivot, LLINT *tmp, int size)
{
	int		median;	

	median = size / 2;
	*pivot = tmp[median];
}

int	find_median(t_body *body, int *pivot, int len, char stack_name)
{
	t_node	*node;
	int		size;
	int		idx;
	LLINT	*tmp;

	tmp = (LLINT *)malloc(sizeof(LLINT) * len);
	if (tmp == NULL)
		return (error(""));
	if (stack_name == 'a')
		node = A_TOP;
	else
		node = B_TOP;
	size = len;
	idx = 0;
	while (--size >= 0)
	{
		tmp[idx++] = node->value;
		node = node->next;
	}
	merge_sort(tmp, 0, len - 1);
	get_median(pivot, tmp, len);
	free(tmp);
	return (1);
}
