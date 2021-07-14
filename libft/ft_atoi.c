/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:16:07 by joonpark          #+#    #+#             */
/*   Updated: 2021/05/11 15:58:30 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(const char c)
{
	return (c == '\r' || c == '\t' ||
			c == '\n' || c == '\v' ||
			c == '\f' || c == ' ');
}

static int	ft_isnum(const char c)
{
	return (c >= '0' && c <= '9');
}

static int	calculate(const char *str, int minus)
{
	int	ret;

	ret = 0;
	while (*str)
	{
		if (ft_isnum(*str))
		{
			ret *= 10;
			ret += (*str - '0');
		}
		else
			break ;
		++str;
	}
	if (minus == -1)
		ret = -ret;
	return (ret);
}

int			ft_atoi(const char *str)
{
	int	ret;
	int	minus;

	while (ft_isspace(*str))
		++str;
	minus = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus = -1;
		++str;
	}
	if (!ft_isnum(*str))
		return (0);
	ret = calculate(str, minus);
	return (ret);
}
