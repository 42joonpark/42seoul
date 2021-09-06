/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 12:01:00 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/01 21:41:19 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	info_stack_init(t_istack *s)
{
	if (s == NULL)
		return (error(""));
	s->top = NULL;
	return (1);
}

int	info_is_empty(t_istack *s)
{
	if (s == NULL)
		return (error(""));
	return (s->top == NULL);
}

int	info_push_top(t_istack *s, t_info *info)
{
	if (s == NULL)
		return (error(""));
	if (info == NULL)
		return (error(""));
	if (!info_is_empty(s))
		info->next = s->top;
	s->top = info;
	return (1);
}

t_info	*info_pop_top(t_istack *s)
{
	t_info	*ret;

	if (info_is_empty(s))
		return (ptr_error(""));
	ret = s->top;
	s->top = ret->next;
	return (ret);
}

int	free_istack(t_istack *s)
{
	t_info	*info;

	if (s != NULL)
	{
		while (!info_is_empty(s))
		{
			info = info_pop_top(s);
			free(info);
		}
		free(s);
	}
	return (1);
}
