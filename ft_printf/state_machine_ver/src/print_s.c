/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:13:54 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/09 18:15:46 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_header.h"

static int	get_actual_length(const char *str, int length)
{
	int		ret;

	ret = 0;
	while (*str != '\0' && ret < length)
	{
		++ret;
		++str;
	}
	return (ret);
}

static void	print_width_larger(ft_opt *format, char *p, int n)
{
	int		t;

	format->tot += format->width;
	if (format->hypen)
	{
		t = n;
		while (n-- > 0)
			write(1, p++, 1);
		n = t;
		while (n++ < format->width)
			write(1, &format->padc, 1);
	}
	else
	{
		t = n;
		while (n++ < format->width)
			write(1, &format->padc, 1);
		n = t;
		while (n-- > 0)
			write(1, p++, 1);
	}
}

int			print_s(va_list ap, ft_opt *format)
{
	int		n;
	char	*p;

	p = va_arg(ap, char *);
	if (format->length < 0)
		format->length = 2147483647;
	if (p == NULL)
		p = "(null)";
	n = get_actual_length(p, format->length);
	if (format->width <= n)
	{
		format->tot += n;
		while (n-- > 0)
			write(1, p++, 1);
	}
	else
	{
		print_width_larger(format, p, n);
	}
	return (0);
}
