/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:59:22 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/10 11:07:41 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "state_machine.h"
#include "print_header.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

static int		get_flags(const char *str, va_list ap, ft_opt *opt)
{
	const char	*t;
	int			state;
	int			token;

	t = str;
	state = 0;
	init_opt(opt);
	while (*str)
	{
		token = get_token(*str);
		state = get_state(state, token);
		if (state == 1)
			write(1, str, 1);
		if (state == 2)
		{
			if (*str == '-')
			{
				opt->hypen = 1;
				opt->padc = ' ';
			}
			else if (*str == '0' && opt->hypen != 1)
				opt->padc = '0';
		}
		if (state == 3)
		{
			opt->width *= 10;
			opt->width += (*str - '0');
		}
		if (state == 4)
		{
			opt->width = va_arg(ap, int);
			if (opt->width < 0 && !opt->hypen)
			{
				opt->hypen = 1;
				opt->padc = ' ';
			}
			if (opt->width < 0)
				opt->width = -opt->width;
		}
		if (state == 5)
		{
			opt->dot = 1;
			opt->length = 0;
		}
		if (state == 6)
		{
			opt->length *= 10;
			opt->length += (*str - '0');
		}
		if (state == 7)
			opt->length = va_arg(ap, int);
		if (state == 8 || state == 10) // 현재 % 에 대한 것들은 다 읽은 거니까 종료해야지
			break ;
		if (state == -1)
			return (-1);
		str++;
	}
	return (str - t);
}

static int		prec_to_num(char c)
{
	static const char	*mapping = "csdiuxXp%";
	int					idx;

	idx = 0;
	while (mapping[idx])
	{
		if (mapping[idx] == c)
			return (idx);
		++idx;
	}
	return (-1);
}

static int		ft_helper(const char *str, va_list ap)
{
	int			ret;
	int			cnt;
	int			p2n;
	int			(*fp[PRECISION_NUMBER])(va_list, ft_opt *);
	ft_opt		opt;

	fp[PRECISION_C]				= print_c_state;
	fp[PRECISION_S]				= print_s;
	fp[PRECISION_D]				= print_d;
	fp[PRECISION_I]				= print_d;
	fp[PRECISION_U]				= print_u;
	fp[PRECISION_X]				= print_x;
	fp[PRECISION_XX]			= print_xx;
	fp[PRECISION_P]				= print_p;
	fp[PRECISION_PERCENTAGE]	= print_percentage;
	ret = 0;
	while (*str)
	{
		cnt = get_flags(str, ap, &opt);
		if (ret == -1)
		{
			write(1, "ERROR!\n", 7);
			return (-1);
		}
		str += cnt;
		p2n = prec_to_num(*str);
		if (p2n >= 0)
		{
			fp[p2n](ap, &opt);
			++str;
		}
		ret += opt.tot;
	}
	return (ret);
}

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	int			res;

	va_start(ap, str);
	res = ft_helper(str, ap);
	va_end(ap);
	return (res);
}
