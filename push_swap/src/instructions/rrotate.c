/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 18:35:00 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/03 14:52:04 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rrotate(t_stack *s)
{
	if (is_empty(s))
		return (error(""));
	s->top = s->bot;
	s->bot = s->bot->prev;
	return (1);
}

int	rra(t_body *body, int flag)
{
	int	res;

	res = rrotate(body->stack_a);
	if (res < 0)
		return (error(""));
	if (flag == 0)
	{
		write(STDOUT_FILENO, "rra\n", 4);
		body->ins_ct++;
	}
	return (1);
}

int	rrb(t_body *body, int flag)
{
	int	res;

	res = rrotate(body->stack_b);
	if (res < 0)
		return (error(""));
	if (flag == 0)
	{
		write(STDOUT_FILENO, "rrb\n", 4);
		body->ins_ct++;
	}
	return (1);
}

int	rrr(t_body *body, int flag)
{
	int	res;

	res = rra(body, 1);
	if (res < 0)
		return (error(""));
	res = rrb(body, 1);
	if (res < 0)
		return (error(""));
	if (flag == 0)
	{
		body->ins_ct++;
		write(STDOUT_FILENO, "rrr\n", 4);
	}
	return (1);
}
