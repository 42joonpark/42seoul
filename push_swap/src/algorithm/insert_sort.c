/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 11:53:30 by joonpark          #+#    #+#             */
/*   Updated: 2021/08/14 18:36:56 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	insert_sort(LLINT *arr, int size)
{
	int		idx;
	int		i;
	LLINT	data;

	idx = 1;
	while (idx < size)
	{
		data = arr[idx];
		i = idx - 1;
		while (i >= 0)
		{
			if (arr[i] > data)
				arr[i + 1] = arr[i];
			else
				break ;
			--i;
		}
		arr[i + 1] = data;
		++idx;
	}	
	return (1);
}
