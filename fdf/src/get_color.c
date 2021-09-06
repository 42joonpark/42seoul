/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:22:38 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/23 13:50:54 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_in_hex_fam(char c)
{
	static const char	*hex_fam1 = "0123456789abcdef";
	static const char	*hex_fam2 = "0123456789ABCDEF";
	int					idx;

	idx = 0;
	while (idx < 16)
	{
		if (hex_fam1[idx] == c || hex_fam2[idx] == c)
			return (idx);
		++idx;
	}
	return (-1);
}

static int	get_color_decimal(const char *str)
{
	int					ret;
	int					val;

	ret = 0;
	while (*str)
	{
		val = is_in_hex_fam(*str);
		if (val == -1)
			return (-1);
		ret *= 16;
		ret += val;
		++str;
	}
	return (ret);
}

int			get_color(const char *line)
{
	int		idx;
	int		ret;

	idx = 0;
	ret = -1;
	while (line[idx] != '\0' && line[idx] != ',')
		++idx;
	if (line[idx] == '\0')
		return (0x000000);
	if (line[idx] == ',' && line[idx + 1] == '0')
	{
		idx += 3;
		ret = get_color_decimal(line + idx);
	}
	return (ret);
}
