/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 20:50:56 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/03 12:38:00 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

#include <stdio.h>
int	push_swap(t_body *body)
{
	if (get_stack_length(body->stack_a) == 5)
		sort_small(body, 5);
	else
		a_to_b(body, get_stack_length(body->stack_a));
	return (1);
}
