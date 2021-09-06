/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_program_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 11:01:42 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/04 11:02:20 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	do_p(t_body *body, const char *line)
{
	if (js_strcmp(line, "pa") == 0)
		pa(body, 1);
	else if (js_strcmp(line, "pb") == 0)
		pb(body, 1);
	else
		return (-1);
	return (1);
}

static int	do_s(t_body *body, const char *line)
{
	if (js_strcmp(line, "sa") == 0)
		sa(body, 1);
	else if (js_strcmp(line, "sb") == 0)
		sb(body, 1);
	else if (js_strcmp(line, "ss") == 0)
		ss(body, 1);
	else
		return (-1);
	return (1);
}

static int	do_r(t_body *body, const char *line)
{
	if (js_strcmp(line, "ra") == 0)
		ra(body, 1);
	else if (js_strcmp(line, "rb") == 0)
		rb(body, 1);
	else if (js_strcmp(line, "rr") == 0)
		rr(body, 1);
	else if (js_strcmp(line, "rra") == 0)
		rra(body, 1);
	else if (js_strcmp(line, "rrb") == 0)
		rrb(body, 1);
	else if (js_strcmp(line, "rrr") == 0)
		rrr(body, 1);
	else
		return (-1);
	return (1);
}

static int	free_and_return(char *line)
{
	if (line)
	{
		free(line);
		line = NULL;
	}
	return (-1);
}

int	checker_program_helper(t_body *body, char *line)
{
	if (line[0] == 'p')
	{
		if (do_p(body, line) < 0)
			return (free_and_return(line));
	}
	else if (line[0] == 's')
	{
		if (do_s(body, line) < 0)
			return (free_and_return(line));
	}
	else if (line[0] == 'r')
	{
		if (do_r(body, line) < 0)
			return (free_and_return(line));
	}
	else
		return (free_and_return(line));
	return (1);
}
