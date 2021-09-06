/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 18:30:57 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/03 14:27:52 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_stack(t_stack *s)
{
	t_node	*node;

	if (s != NULL)
	{
		while (!is_empty(s))
		{
			node = pop_top(s);
			free(node);
		}
		free(s);
	}
	else
		return (error(""));
	return (1);
}

int	get_stack_length(t_stack *s)
{
	t_node	*node;
	int		ret;

	ret = 0;
	if (s != NULL)
	{
		node = s->top;
		while (node != s->bot)
		{
			++ret;
			node = node->next;
		}
		if (!is_empty(s))
			++ret;
	}
	return (ret);
}

int	is_stack_sorted(t_stack *s)
{
	t_node	*node;
	LLINT	val;

	val = s->top->value;
	node = s->top->next;
	while (node != s->top)
	{
		if (node->value < val)
			return (0);
		val = node->value;
		node = node->next;
	}
	return (1);
}
