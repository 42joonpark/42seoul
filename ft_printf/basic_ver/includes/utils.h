/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:52:14 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/03 13:33:04 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	print_str(const char *str);
void	print_number(long long int number);
void	print_number_hex(long long int number, int flag);
int		get_number_length(long long int number, int base);

#endif
