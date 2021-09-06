/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:04:37 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/09 18:14:55 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_opt.h"

void				init_opt(ft_opt *opt)
{
	opt->flag = 0;
	opt->width = 0;
	opt->dot = 0;
	opt->length = -1;
	opt->hypen = 0;
	opt->padc = ' ';
	opt->tot = 0;
}
