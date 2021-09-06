/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:04:06 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/09 18:15:08 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPT_H
# define FT_OPT_H

typedef struct		ft_opt
{
	int				flag;
	int				width;
	int				dot;
	int				length;
	int				hypen;
	int				tot;
	char			padc;
}					ft_opt;

void				init_opt(ft_opt *opt);

#endif
