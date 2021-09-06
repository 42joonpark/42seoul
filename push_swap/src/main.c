/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 08:40:39 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/01 21:41:09 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_numbers(t_body *body, t_arr *numbers)
{
	t_node	*node;
	int		size;

	size = numbers->size;
	body->size = size;
	while (size > 0)
	{
		node = get_new_node(numbers->arr[size - 1]);
		if (node == NULL)
			return (error(""));
		push_top(body->stack_a, node);
		--size;
	}
	return (1);
}

static int	run(t_arr *numbers)
{
	t_body	*body;

	body = (t_body *)malloc(sizeof(t_body));
	if (body == NULL)
		return (fatal_body(body, "run() : failed to create t_body.\n"));
	if (init_body(body) < 0)
		return (fatal_body(body, "run() : failed to init t_body.\n"));
	if (push_numbers(body, numbers) < 0)
		return (fatal_body(body, "run() : failed to push t_body.\n"));
	push_swap(body);
	return (free_body(body));
}

static int	is_sorted(t_arr *numbers)
{
	int	idx;
	int	size;

	idx = 0;
	size = numbers->size;
	while (++idx < size)
	{
		if (numbers->arr[idx] < numbers->arr[idx - 1])
			return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_arr	numbers;

	if (check(&numbers, argc, argv) == NULL)
		fatal("Error\n");
	if (is_sorted(&numbers))
		exit(0);
	if (run(&numbers) < 0)
		fatal("Error\n");
	exit(EXIT_SUCCESS);
}
