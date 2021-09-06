/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 12:12:18 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/01 14:52:31 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	*get_new_info(int size, char stack_name)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	info->size = size;
	info->stack_name = stack_name;
	info->next = NULL;
	return (info);
}
