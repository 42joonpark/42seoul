/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:52:00 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/09 18:52:10 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <unistd.h>

void	print_str(const char *str)
{
	while (*str)
	{
		write(1, str, 1);
		++str;
	}
}

void	print_number(long long int number)
{
	char	c;

	if (number == -2147483648)
	{
		print_number(number / 10);
		write(1, &"8", 1);
	}
	else if (number < 0)
	{
		print_number(number * -1);
	}
	else
	{
		if (number > 9)
			print_number(number / 10);
		c = (number % 10 + '0');
		write(1, &c, 1);
	}
}

void	print_number_hex(long long int number, int flag)
{
	static const char	*lower = "0123456789abcdef";
	static const char	*upper = "0123456789ABCDEF";
	char				c;

	if (number < 0)
	{
		print_number_hex(-number, flag);
	}
	else
	{
		if (number > 15)
			print_number_hex(number / 16, flag);
		if (flag)
			c = upper[number % 16];
		else
			c = lower[number % 16];
		write(1, &c, 1);
	}
}

int		get_number_length(long long int number, int base)
{
	int		ret;

	ret = 0;
	if (number < 0)
		number = -number;
	while (number >= 0)
	{
		++ret;
		number /= base;
		if (number == 0)
			break ;
	}
	return (ret);
}

