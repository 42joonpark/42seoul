/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 16:35:13 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/02 10:17:32 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_pivot(t_pivot *pivot, LLINT *tmp, int size)
{
	int		t_to_f;	

	t_to_f = size / 3;
	pivot->size1 = t_to_f;
	pivot->size2 = t_to_f;
	PIVOT1 = tmp[t_to_f];
	PIVOT2 = tmp[t_to_f + t_to_f];
}

int	find_pivot(t_body *body, t_pivot *pivot, int stack_len, char stack_name)
{
	t_node	*node;
	int		size;
	int		idx;
	LLINT	*tmp;

	tmp = (LLINT *)malloc(sizeof(LLINT) * stack_len);
	if (tmp == NULL)
		return (error(""));
	if (stack_name == 'a')
		node = A_TOP;
	else
		node = B_TOP;
	size = stack_len;
	idx = 0;
	while (--size >= 0)
	{
		tmp[idx++] = node->value;
		node = node->next;
	}
	merge_sort(tmp, 0, stack_len - 1);
	get_pivot(pivot, tmp, stack_len);
	free(tmp);
	return (1);
}
