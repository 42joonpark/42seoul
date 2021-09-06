/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_body.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:56:18 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/03 08:34:01 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_body.h"

void		t_format_init(t_format *format)
{
	format->padc = ' ';
	format->hypen = 0;
	format->aestrik = 0;
	format->width = 0;
	format->length = -1;
	format->precision = 0;
	format->count = 0;
	format->tot = 0;
}
