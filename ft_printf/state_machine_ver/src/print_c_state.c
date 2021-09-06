/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 10:46:27 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/10 11:50:18 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_header.h"

enum 		inputs
{
	HYPEN = 0,
	NO_HYPEN,
	NO_FLAG,
	WIDTH,
	ZERO_WIDTH
};

static int			get_state(int state, int input)
{
	int		arr[20] = {	 
						 1,	 2,	-1,	-1,	-1,
						-1,	-1,	-1,	 2,	 3,
						-1,	-1,	 1,	 2,	 3,
						 3,	 3,	 3,	 3,	 3 
					};

	return (arr[state * 5 + input]);
}

int					print_c_state(va_list ap, ft_opt *opt)
{
	int		f;
	int		state;
	int		input;
	char	val;

	f = 0;
	state = 0;
	input = opt->hypen ? HYPEN : NO_HYPEN;
	while (1)
	{
		state = get_state(state, input);
		if (state == 1)
		{
			f = 1;
			val = va_arg(ap, int);
			write(1, &val, 1);
			input = opt->width == 0 ? ZERO_WIDTH : WIDTH;
		}
		if (state == 2)
		{
			if (opt->width > 0)
				--opt->width;
			input = opt->width == 0 ? ZERO_WIDTH : WIDTH;
			if (input == WIDTH)
				write(1, &" ", 1);
			input = (f == 0 && opt->width == 0) ? NO_FLAG : input;
		}
		if (state == 3)
			break ;
		if (state == -1)
			return (-1);
	}
	return (0);
}
