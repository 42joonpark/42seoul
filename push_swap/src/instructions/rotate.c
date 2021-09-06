/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 18:34:52 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/03 14:49:49 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_stack *s)
{
	if (is_empty(s))
		return (error(""));
	s->bot = s->top;
	s->top = s->top->next;
	return (1);
}

int	ra(t_body *body, int flag)
{
	int	res;

	res = rotate(body->stack_a);
	if (res < 0)
		return (error(""));
	if (flag == 0)
	{
		write(STDOUT_FILENO, "ra\n", 3);
		body->ins_ct++;
	}
	return (1);
}

int	rb(t_body *body, int flag)
{
	int	res;

	res = rotate(body->stack_b);
	if (res < 0)
		return (error(""));
	if (flag == 0)
	{
		write(STDOUT_FILENO, "rb\n", 3);
		body->ins_ct++;
	}
	return (1);
}

int	rr(t_body *body, int flag)
{
	int	 res;

	res = ra(body, 1);
	if (res < 0)
		return (error(""));
	res = rb(body, 1);
	if (res < 0)
		return (error(""));
	if (flag == 0)
	{
		body->ins_ct++;
		write(STDOUT_FILENO, "rr\n", 3);
	}
	return (1);
}
