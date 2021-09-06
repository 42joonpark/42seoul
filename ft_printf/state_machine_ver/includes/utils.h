/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:51:40 by joonpark          #+#    #+#             */
/*   Updated: 2021/06/09 18:51:48 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	print_str(const char *str);
void	print_number(long long int number);
void	print_number_hex(long long int number, int flag);
int		get_number_length(long long int number, int base);

#endif

