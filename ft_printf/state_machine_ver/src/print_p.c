/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:54:39 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/09 18:54:56 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_header.h"
#include "utils.h"

static void	print_without_zero(ft_opt *format, int n, int t)
{
	while (t-- > 0)
		write(1, &format->padc, 1);
	write(1, &"0x", 2);
	format->width -= 2;
	t = format->length - n;
	if (t > 0)
		format->tot += t;
	while (t-- > 0)
		write(1, &"0", 1);
}

static void	print_without_hypen(ft_opt *format, long long int number, int n)
{
	int		t;

	t = format->width - (format->length > n ? format->length : n);
	if (t - 2 > 0)
		format->tot += (t - 2);
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
		print_without_zero(format, n, t - 2);
	print_number_hex(number, 0);
	format->tot += 2;
}

static void	print_width_larger(ft_opt *format, long long int number, int n)
{
	int		t;

	if (format->hypen)
	{
		t = format->length - n;
		if (t > 0)
			format->tot += t;
		write(1, &"0x", 2);
		format->width -= 2;
		while (t-- > 0)
			write(1, &"0", 1);
		print_number_hex(number, 0);
		format->tot += 2;
		t = format->width - (format->length > n ? format->length : n);
		if (t > 0)
			format->tot += t;
		while (t-- > 0)
			write(1, &format->padc, 1);
	}
	else
		print_without_hypen(format, number, n);
}

static int	handle_zero_with_prec(ft_opt *format)
{
	long long int	t;

	format->width -= 2;
	t = format->width;
	if (t > 0)
		format->tot += t;
	if (format->hypen)
	{
		write(1, &"0x", 2);
		while (t-- > 0)
			write(1, &" ", 1);
	}
	else
	{
		while (t-- > 0)
			write(1, &" ", 1);
		write(1, &"0x", 2);
	}
	format->tot += 2;
	return (0);
}

int			print_p(va_list ap, ft_opt *format)
{
	long long int	number;
	int				n;

	number = (long long int)va_arg(ap, char *);
	if (format->length >= 0)
		format->padc = ' ';
	if (number == 0 && format->length == 0)
		return (handle_zero_with_prec(format));
	n = get_number_length(number, 16);
	format->tot += n;
	print_width_larger(format, number, n);
	return (0);
}

