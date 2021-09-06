/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 14:54:07 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/04 09:52:33 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_rest(t_body *body, int r_cnt[])
{
	while (r_cnt[A_STACK] > 0 && r_cnt[B_STACK] > 0)
	{
		rrr(body, 0);
		--r_cnt[A_STACK];
		--r_cnt[B_STACK];
	}
	while (r_cnt[A_STACK]-- > 0)
		rra(body, 0);
	while (r_cnt[B_STACK]-- > 0)
		rrb(body, 0);
}

static void	helper(t_body *body, int r_cnt[], t_pivot *pivot, int len)
{
	find_pivot(body, pivot, len, 'b');
	while (--len >= 0)
	{
		if (B_TOP->value < pivot->first)
		{
			rb(body, 0);
			r_cnt[B_STACK]++;
		}
		else
		{
			pa(body, 0);
			if (A_TOP->value < pivot->second)
			{
				ra(body, 0);
				r_cnt[A_STACK]++;
			}
		}
	}
}

static void	handle_small(t_body *body, int len)
{
	int	arg;

	arg = len;
	while (len > 0)
	{
		pa(body, 0);
		--len;
	}
	a_to_b(body, arg);
}

int	b_to_a(t_body *body, int len)
{
	int		r_cnt[2];
	int		arg[3];
	t_pivot	pivot;

	r_cnt[A_STACK] = 0;
	r_cnt[B_STACK] = 0;
	if (len > 3)
	{
		helper(body, r_cnt, &pivot, len);
		arg[0] = r_cnt[B_STACK];
		arg[1] = len - arg[0];
		arg[2] = r_cnt[A_STACK];
		a_to_b(body, arg[1] - arg[2]);
		move_rest(body, r_cnt);
		a_to_b(body, arg[2]);
		b_to_a(body, arg[2]);
	}
	else
		handle_small(body, len);
	return (1);
}
