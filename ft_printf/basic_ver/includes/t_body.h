/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_body.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:49:35 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/03 13:23:53 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_BODY_H
# define T_BODY_H

typedef struct	s_format
{
	char	padc;
	int		hypen;
	int		aestrik;
	int		width;
	int		length;
	int		precision;
	int		count;
	int		tot;
}				t_format;
void			t_format_init(t_format *format);

#endif
