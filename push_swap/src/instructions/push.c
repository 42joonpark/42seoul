/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 18:34:45 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/03 14:51:08 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_stack *s, t_node *node)
{
	int	res;

	res = push_top(s, node);
	if (res < 0)
		return (error(""));
	return (1);
}

int	pa(t_body *body, int flag)
{
	int		res;
	t_node	*node;

	node = pop_top(body->stack_b);
	if (node == NULL)
		return (error(""));
	res = push(body->stack_a, node);
	if (res < 0)
		return (error(""));
	if (flag == 0)
	{
		write(STDOUT_FILENO, "pa\n", 3);
		body->ins_ct++;
	}
	return (1);
}

int	pb(t_body *body, int flag)
{
	int		res;
	t_node	*node;

	node = pop_top(body->stack_a);
	if (node == NULL)
		return (error(""));
	res = push(body->stack_b, node);
	if (res < 0)
		return (error(""));
	if (flag == 0)
	{
		write(STDOUT_FILENO, "pb\n", 3);
		body->ins_ct++;
	}
	return (1);
}
