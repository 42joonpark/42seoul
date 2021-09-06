/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 17:01:21 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/23 12:57:58 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(t_point *point)
{
	int			o_x;
	int			o_y;

	o_x = point->x;
	o_y = point->y;
	point->x = (o_x - o_y) * cos(M_PI / 180 * 30);
	point->y = (o_x + o_y) * sin(M_PI / 180 * 30) - point->z;
}
