/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 12:49:17 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/04 11:02:18 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_result(t_body *body)
{
	if (is_empty(body->stack_b) && is_stack_sorted(body->stack_a))
		return (1);
	return (-1);
}

int	checker_program(t_body *body)
{
	char	*line;
	int		res;

	line = NULL;
	while (get_line(STDIN_FILENO, &line) > 0)
	{
		res = checker_program_helper(body, line);
		if (res < 0)
			return (-1);
		if (line)
			free(line);
		line = NULL;
	}
	if (line)
		free(line);
	if (check_result(body) < 0)
		return (0);
	return (1);
}
