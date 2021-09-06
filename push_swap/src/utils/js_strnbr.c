/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   js_strnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 20:19:50 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/01 14:52:02 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	is_space(char c)
{
	return (c == '\n' || c == '\r' || c == ' '
		|| c == '\t' || c == '\f' || c == '\v');
}

static	int	skip_front(const char **str, int *minus)
{
	while (is_space(**str))
		++(*str);
	while (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*minus = 1;
		++(*str);
	}
	if (**str == '0' && *(*str + 1) != '\0')
		return (-1);
	return (1);
}

t_nbr	js_strnbr(const char *str)
{
	t_nbr	ret;
	int		minus;

	minus = 0;
	ret.val = 0;
	if (skip_front(&str, &minus) < 0)
	{
		ret.res = -1;
		return (ret);
	}
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
		{
			ret.res = -1;
			return (ret);
		}
		ret.val *= 10;
		ret.val += (*str - '0');
		++str;
	}
	if (minus)
		ret.val *= -1;
	ret.res = 1;
	return (ret);
}
