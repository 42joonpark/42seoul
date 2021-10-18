/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:48:31 by joonpark          #+#    #+#             */
/*   Updated: 2021/10/05 17:23:42 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	js_isdigit(char *arg)
{
	int	idx;

	idx = 0;
	while (arg[idx] && (arg[idx] == '-' || arg[idx] == '+'))
		++idx;
	if (!(arg[idx] >= '0' && arg[idx] <= '9'))
		return (0);
	while (arg[idx])
	{
		if (!(arg[idx] >= '0' && arg[idx] <= '9'))
			return (0);
		++idx;
	}
	return (1);
}

static int	js_atoi(char *arg)
{
	long	val;
	int		minus;
	int		idx;

	val = 0;
	minus = 0;
	idx = 0;
	while (arg[idx] && (arg[idx] == '-' || arg[idx] == '+'))
	{
		if (arg[idx++] == '-')
			minus = 1;
	}
	while (arg[idx])
	{
		val = val * 10 + (arg[idx] - '0');
		++idx;
	}
	if (minus)
		val *= -1;
	if (val > INT_MAX)
		return (error("js_atoi(): number over INT_MAX.\n"));
	if (val < 0)
		return (error("js_atoi(): number < 0.\n"));
	return ((int)val);
}

int	get_argument(char *arg)
{
	int	ret;

	if (!js_isdigit(arg))
		return (error("get_argument(): Not a digit.\n"));
	ret = js_atoi(arg);
	return (ret);
}
