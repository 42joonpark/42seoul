/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 13:46:59 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/03 12:38:33 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_init(t_stack *s)
{
	if (s == NULL)
		return (error(""));
	s->top = NULL;
	s->bot = NULL;
	s->length = 0;
	return (1);
}

int	is_empty(t_stack *s)
{
	if (s == NULL)
		return (error(""));
	return (s->top == NULL && s->length == 0);
}

int	push_top(t_stack *s, t_node *node)
{
	if (s == NULL)
		return (error(""));
	if (node == NULL)
		return (error(""));
	if (is_empty(s))
	{
		node->next = node;
		node->prev = node;
		s->bot = node;
	}
	else
	{
		s->top->prev = node;
		node->next = s->top;
		s->bot->next = node;
		node->prev = s->bot;
	}
	s->top = node;
	s->length++;
	return (1);
}

t_node	*pop_top(t_stack *s)
{
	t_node	*ret;

	if (is_empty(s))
		return (ptr_error(""));
	ret = s->top;
	if (s->length == 1)
	{
		s->top = NULL;
		s->bot = NULL;
	}
	else
	{
		s->top = ret->next;
		s->top->prev = ret->prev;
		s->bot->next = s->top;
	}
	s->length--;
	return (ret);
}
