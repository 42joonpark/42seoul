/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:56:06 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/04 09:52:09 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_rest(t_body *body, int r_cnt[])
{
	while (r_cnt[A_STACK] > 0 && r_cnt[B_STACK] > 0 && body->flag == 1)
	{
		rrr(body, 0);
		--r_cnt[A_STACK];
		--r_cnt[B_STACK];
	}
	while (r_cnt[A_STACK]-- > 0 && body->flag == 1)
		rra(body, 0);
	while (r_cnt[B_STACK]-- > 0)
		rrb(body, 0);
}

static void	helper(t_body *body, int r_cnt[], t_pivot *pivot, int len)
{
	find_pivot(body, pivot, len, 'a');
	while (--len >= 0)
	{
		if (A_TOP->value >= pivot->second)
		{
			ra(body, 0);
			r_cnt[A_STACK]++;
		}
		else
		{
			pb(body, 0);
			if (B_TOP->value >= pivot->first)
			{
				rb(body, 0);
				r_cnt[B_STACK]++;
			}
		}
	}
}

static void	do_5(t_body *body)
{
	int	median;
	int	cnt[2];

	find_median(body, &median, 5, 'a');
	cnt[0] = 0;
	cnt[1] = 0;
	while (cnt[0] < 2)
	{
		if (A_TOP->value < median)
		{
			pb(body, 0);
			++cnt[0];
		}
		else
		{
			ra(body, 0);
			++cnt[1];
		}
	}
	while (--cnt[1] >= 0)
		rra(body, 0);
	sort_small(body, 3);
	pa(body, 0);
	pa(body, 0);
	sort_small(body, 2);
}

static void	handle_small(t_body *body, int len)
{
	sort_small(body, len);
	if (body->flag == 0)
		body->flag = 1;
}

int	a_to_b(t_body *body, int len)
{
	int		r_cnt[2];
	int		arg[3];
	t_pivot	pivot;

	r_cnt[A_STACK] = 0;
	r_cnt[B_STACK] = 0;
	if (len == 5)
		do_5(body);
	else if (len > 3)
	{
		helper(body, r_cnt, &pivot, len);
		arg[0] = r_cnt[A_STACK];
		arg[1] = len - arg[0];
		arg[2] = r_cnt[B_STACK];
		move_rest(body, r_cnt);
		a_to_b(body, arg[0]);
		b_to_a(body, arg[2]);
		b_to_a(body, arg[1] - arg[2]);
	}
	else
		handle_small(body, len);
	return (1);
}
