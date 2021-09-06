/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:47:47 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/03 13:22:37 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_H
# define HANDLE_H

# include "t_body.h"
# include <stdarg.h>

int		handle_flag(const char *str, va_list ap, t_format *format);
int		handle_width(const char *str, va_list ap, t_format *format);
int		handle_dot(const char *str, va_list ap, t_format *format);
int		handle_length(const char *str, va_list ap, t_format *format);

#endif
