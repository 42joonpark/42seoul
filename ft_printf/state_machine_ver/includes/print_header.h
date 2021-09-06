/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_header.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:45:26 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/10 11:07:17 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_HEADER_H
# define PRINT_HEADER_H

# include "ft_opt.h"
# include <stdarg.h>
# include <unistd.h>

int		print_c(va_list ap, ft_opt *format);
int		print_c_state(va_list ap, ft_opt *format);
int		print_s(va_list ap, ft_opt *format);
int		print_d(va_list ap, ft_opt *format);
int		print_i(va_list ap, ft_opt *format);
int		print_u(va_list ap, ft_opt *format);
int		print_p(va_list ap, ft_opt *format);
int		print_x(va_list ap, ft_opt *format);
int		print_xx(va_list ap, ft_opt *format);
int		print_percentage(va_list ap, ft_opt *format);

#endif
