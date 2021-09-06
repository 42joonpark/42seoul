/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 18:35:08 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/03 14:51:37 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_stack *s)
{
	t_node	*tmp1;
	t_node	*tmp2;
	int		res;

	if (is_empty(s) || s->length == 1)
		return (1);
	tmp1 = pop_top(s);
	if (tmp1 == NULL)
		return (error(""));
	tmp2 = pop_top(s);
	if (tmp2 == NULL)
		return (error(""));
	res = push_top(s, tmp1);
	if (res < 0)
		return (error(""));
	res = push_top(s, tmp2);
	if (res < 0)
		return (error(""));
	return (1);
}

int	sa(t_body *body, int flag)
{
	int	res;

	res = swap(body->stack_a);
	if (res < 0)
		return (error(""));
	if (flag == 0)
	{
		write(STDOUT_FILENO, "sa\n", 3);
		body->ins_ct++;
	}
	return (1);
}

int	sb(t_body *body, int flag)
{
	int	res;

	res = swap(body->stack_b);
	if (res < 0)
		return (error(""));
	if (flag == 0)
	{
		write(STDOUT_FILENO, "sb\n", 3);
		body->ins_ct++;
	}
	return (1);
}

int	ss(t_body *body, int flag)
{
	int	res;

	res = sa(body, 1);
	if (res < 0)
		return (error(""));
	res = sb(body, 1);
	if (res < 0)
		return (error(""));
	if (flag == 0)
	{
		write(STDOUT_FILENO, "ss\n", 3);
		body->ins_ct++;
	}
	return (1);
}
