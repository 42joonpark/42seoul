/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 13:22:03 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/03 11:24:53 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_small(t_body *body, int len)
{
	if (len == 2)
		sort_2(body);
	else if (len == 3)
		sort_3(body);
	else if (len == 5 && get_stack_length(body->stack_a) == 5)
		sort_5(body);
	return (1);
}
