/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:59:32 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/09 20:42:10 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define PRECISION_NUMBER 10

int		ft_printf(const char *str, ...);

enum	PRECISONS
{
	PRECISION_C = 0,
	PRECISION_S,
	PRECISION_D,
	PRECISION_I,
	PRECISION_U,
	PRECISION_X,
	PRECISION_XX,
	PRECISION_P,
	PRECISION_PERCENTAGE
};

#endif


/*
static int		ft_helper(const char *str, va_list ap)
{
	int		state;
	int		prev_state;
	int		token;

	state = 0;
	while (*str)
	{
		prev_state = state;
		token = get_token(*str);
		state = get_state(state, token);
		printf("[%c, %d] %d -> %d\n", *str, token, prev_state, state);
		if (state == 8)
			state = 0;
		if (state == 10)
			break ;
		if (state == -1)
			return (-1);
		str++;
	}
	return (0);
}
 */
