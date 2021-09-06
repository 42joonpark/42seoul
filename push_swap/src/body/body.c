/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   body.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 18:36:03 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/02 15:41:01 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_body(t_body *body)
{
	if (body != NULL)
	{
		free_stack(body->stack_a);
		free_stack(body->stack_b);
		free(body);
	}
	else
		return (error(""));
	return (1);
}

int	fatal_body(t_body *body, const char *msg)
{
	int	res;

	(void)msg;
	res = free_body(body);
	return (error(""));
}

int	init_body(t_body *body)
{
	int	res;

	body->stack_a = (t_stack *)malloc(sizeof(t_stack));
	res = stack_init(body->stack_a);
	if (res < 0)
		return (fatal_body(body, "init_body() : failed to init stack_a.\n"));
	body->stack_b = (t_stack *)malloc(sizeof(t_stack));
	res = stack_init(body->stack_b);
	if (res < 0)
		return (fatal_body(body, "init_body() : failed to init stack_b.\n"));
	body->median = 0;
	body->cur_sort_cnt = 0;
	body->size = 0;
	body->ins_ct = 0;
	body->flag = 0;
	return (1);
}
