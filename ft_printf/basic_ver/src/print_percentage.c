/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percentage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 11:17:01 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/03 13:12:19 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_header.h"
#include "utils.h"

int		print_percentage(t_format *format)
{
	int			width;
	char		val;

	val = '%';
	width = format->width;
	if (format->hypen == 1)
	{
		write(1, &val, 1);
		while (width-- > 1)
			write(1, &format->padc, 1);
	}
	else
	{
		while (width-- > 1)
			write(1, &format->padc, 1);
		write(1, &val, 1);
	}
	format->tot = format->width > 1 ? format->width : 1;
	return (0);
}
