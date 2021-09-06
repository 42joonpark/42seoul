/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:11:31 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/01 21:40:52 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	helper(LLINT	*arr, int size)
{
	int	idx;

	if (size < 32)
		insert_sort(arr, size);
	else
		merge_sort(arr, 0, size - 1);
	idx = 0;
	while (++idx < size)
		if (arr[idx] == arr[idx - 1])
			return (error(""));
	return (1);
}

int	check_duplicate(LLINT *arr, int size)
{
	LLINT	*tmp;
	int		idx;
	int		res;

	tmp = (LLINT *)malloc(sizeof(LLINT) * size);
	if (tmp == NULL)
		return (error(""));
	idx = -1;
	while (++idx < size)
		tmp[idx] = arr[idx];
	res = helper(tmp, size);
	if (res < 0)
	{
		free(tmp);
		return (error(""));
	}
	free(tmp);
	return (1);
}
