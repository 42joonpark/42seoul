/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_header.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 10:20:09 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/03 13:23:16 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_HEADER_H
# define PRINT_HEADER_H

# include "t_body.h"
# include <stdarg.h>
# include <unistd.h>

int		print_c(va_list ap, t_format *format);
int		print_s(va_list ap, t_format *format);
int		print_d(va_list ap, t_format *format);
int		print_i(va_list ap, t_format *format);
int		print_u(va_list ap, t_format *format);
int		print_p(va_list ap, t_format *format);
int		print_x(va_list ap, t_format *format);
int		print_xx(va_list ap, t_format *format);
int		print_percentage(t_format *format);

#endif
