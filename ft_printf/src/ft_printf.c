/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 09:27:58 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/03 13:48:52 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "print_header.h"
#include <unistd.h>
#include <stdarg.h>

static int	do_work(va_list ap, t_format *format, const char *str)
{
	if (*str == 'c')
		print_c(ap, format);
	else if (*str == 's')
		print_s(ap, format);
	else if (*str == 'd' || *str == 'i')
		print_d(ap, format);
	else if (*str == 'u')
		print_u(ap, format);
	else if (*str == 'x')
		print_x(ap, format);
	else if (*str == 'X')
		print_xx(ap, format);
	else if (*str == 'p')
		print_p(ap, format);
	else if (*str == '%')
		print_percentage(format);
	return (0);
}

static int	printf_hellper(const char *str, va_list ap, t_format *format)
{
	int		ret;

	ret = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			t_format_init(format);
			handle_flag(str, ap, format);
			str += format->count;
			do_work(ap, format, str);
			++str;
			ret += format->tot;
		}
		else
		{
			write(1, str, 1);
			++str;
			++ret;
		}
	}
	return (ret);
}

int			ft_printf(const char *str, ...)
{
	int			ret;
	va_list		ap;
	t_format	format;

	va_start(ap, str);
	ret = printf_hellper(str, ap, &format);
	va_end(ap);
	return (ret);
}
