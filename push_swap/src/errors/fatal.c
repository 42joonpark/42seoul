/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 18:48:19 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/01 21:28:53 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fatal(const char *msg)
{
	write(STDERR_FILENO, msg, js_strlen(msg));
	exit(EXIT_SUCCESS);
}
