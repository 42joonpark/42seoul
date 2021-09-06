/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 13:55:19 by joonpark          #+#    #+#             */
/*   Updated: 2021/09/01 21:42:26 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(const char *msg)
{
	write(STDERR_FILENO, msg, js_strlen(msg));
	return (-1);
}

void	*ptr_error(const char *msg)
{
	write(STDERR_FILENO, msg, js_strlen(msg));
	return (NULL);
}
