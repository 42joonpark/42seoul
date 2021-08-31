/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:47:49 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/03 13:29:17 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle.h"
#include "utils.h"

int		handle_flag(const char *str, va_list ap, t_format *format)
{
	while (1)
	{
		++str;
		++format->count;
		if (*str == '-')
			format->hypen = 1;
		else if (*str == '0')
			format->padc = '0';
		else
			break ;
	}
	if (format->hypen)
		format->padc = ' ';
	handle_width(str, ap, format);
	return (0);
}

int		handle_width(const char *str, va_list ap, t_format *format)
{
	if (*str >= '0' && *str <= '9')
	{
		format->width = 0;
		while (*str >= '0' && *str <= '9')
		{
			format->width *= 10;
			format->width += (*str - '0');
			++str;
			++format->count;
		}
	}
	else if (*str == '*')
	{
		format->width = va_arg(ap, int);
		++str;
		++format->count;
	}
	if (format->width < 0 && !format->hypen)
	{
		format->hypen = 1;
		format->padc = ' ';
	}
	format->width = format->width < 0 ? -format->width : format->width;
	handle_dot(str, ap, format);
	return (0);
}

int		handle_dot(const char *str, va_list ap, t_format *format)
{
	if (*str == '.')
	{
		handle_length(++str, ap, format);
		++format->count;
	}
	return (0);
}

int		handle_length(const char *str, va_list ap, t_format *format)
{
	format->length = 0;
	if (*str >= '0' && *str <= '9')
	{
		while (*str >= '0' && *str <= '9')
		{
			format->length *= 10;
			format->length += (*str - '0');
			++str;
			++format->count;
		}
	}
	else if (*str == '*')
	{
		format->length = va_arg(ap, int);
		++str;
		++format->count;
	}
	return (0);
}
