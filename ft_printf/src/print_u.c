/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:35:32 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/03 13:51:36 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_header.h"
#include "utils.h"

static void	print_without_zero(t_format *format, int n, int t)
{
	while (t-- > 0)
		write(1, &format->padc, 1);
	t = format->length - n;
	if (t > 0)
		format->tot += t;
	while (t-- > 0)
		write(1, &"0", 1);
}

static void	print_without_hypen(t_format *format, unsigned int number, int n)
{
	int		t;

	t = format->width - (format->length > n ? format->length : n);
	if (t > 0)
		format->tot += t;
	if (format->padc == '0')
	{
		while (t-- > 0)
			write(1, &format->padc, 1);
		t = format->length - n;
		if (t > 0)
			format->tot += t;
		while (t-- > 0)
			write(1, &"0", 1);
	}
	else
		print_without_zero(format, n, t);
	print_number(number);
}

static void	print_width_larger(t_format *format, unsigned int number, int n)
{
	int		t;

	if (format->hypen)
	{
		t = format->length - n;
		if (t > 0)
			format->tot += t;
		while (t-- > 0)
			write(1, &"0", 1);
		print_number(number);
		t = format->width - (format->length > n ? format->length : n);
		if (t > 0)
			format->tot += t;
		while (t-- > 0)
			write(1, &format->padc, 1);
	}
	else
		print_without_hypen(format, number, n);
}

static void	print_helper(t_format *format, unsigned int number, int n)
{
	int		t;

	if (format->width <= format->length)
	{
		t = format->length - n;
		if (t > 0)
			format->tot += t;
		while (t-- > 0)
			write(1, &"0", 1);
		print_number(number);
	}
	else
		print_width_larger(format, number, n);
}

int			print_u(va_list ap, t_format *format)
{
	unsigned int	number;
	unsigned int	t;
	int				n;

	number = (unsigned int)va_arg(ap, int);
	if (format->length >= 0)
		format->padc = ' ';
	if (number == 0 && format->length == 0)
	{
		t = format->width;
		while (t-- > 0)
			write(1, &" ", 1);
		format->tot += format->width;
		return (0);
	}
	if (format->length < 0)
		format->length = 0;
	n = get_number_length(number, 10);
	format->tot += n;
	print_helper(format, number, n);
	return (0);
}
