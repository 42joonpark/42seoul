/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 11:26:46 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/04 09:51:26 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_body *body)
{
	LLINT	val1;
	LLINT	val2;

	val1 = body->stack_a->top->value;
	val2 = body->stack_a->top->next->value;
	if (val1 > val2)
		sa(body, 0);
}

static void	sort_3_helper(t_body *body, LLINT num[])
{
	if (num[1] < num[0] && num[0] < num[2])
		sa(body, 0);
	else if (num[0] > num[2] && num[1] < num[2])
		ra(body, 0);
	else if (num[1] > num[2] && num[2] < num[0])
	{
		sa(body, 0);
		rra(body, 0);
	}
}

static void	sort_big_3(t_body *body, LLINT num[])
{
	if (num[0] < num[1] && num[1] < num[2])
		;
	else if ((num[0] < num[1] && num[1] > num[2] && num[0] < num[2])
		|| (num[0] < num[1] && num[1] > num[2] && num[0] > num[2])
		|| (num[0] > num[1] && num[1] < num[2] && num[2] < num[0])
		|| (num[0] > num[1] && num[1] > num[2] && num[0] > num[2]))
	{
		if (num[0] > num[1] && num[1] < num[2] && num[2] < num[0])
			sa(body, 0);
		if (num[0] > num[1] && num[1] > num[2] && num[0] > num[2])
			sa(body, 0);
		ra(body, 0);
		sa(body, 0);
		rra(body, 0);
		if (num[0] < num[1] && num[1] > num[2] && num[0] > num[2])
			sa(body, 0);
		if (num[0] > num[1] && num[1] > num[2] && num[0] > num[2])
			sa(body, 0);
	}
	else
		sa(body, 0);
}

void	sort_3(t_body *body)
{
	LLINT	num[3];
	t_stack	*tmp;

	tmp = body->stack_a;
	num[0] = tmp->top->value;
	num[1] = tmp->top->next->value;
	num[2] = tmp->top->next->next->value;
	if (get_stack_length(tmp) > 3)
	{
		sort_big_3(body, num);
		return ;
	}
	if (num[0] < num[1])
	{
		if (num[0] < num[2] && num[1] > num[2])
		{
			sa(body, 0);
			ra(body, 0);
		}
		else if (num[0] > num[2])
			rra(body, 0);
	}
	else
		sort_3_helper(body, num);
}

void	sort_5(t_body *body)
{
	int	pb_cnt;
	int	median;

	find_median(body, &median, 5, 'a');
	pb_cnt = 0;
	while (pb_cnt < 2)
	{
		if (A_TOP->value < median)
		{
			pb(body, 0);
			pb_cnt++;
		}
		else
			ra(body, 0);
	}
	if (A_TOP->value > median)
		ra(body, 0);
	sort_3(body);
	pa(body, 0);
	pa(body, 0);
	sort_2(body);
}
