/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 12:59:56 by joonpark          #+#    #+#             */
/*   Updated: 2021/07/15 13:04:22 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_child(t_arg *arg, const char *msg)
{
	perror(msg);
	free_args(arg);
	exit(EXIT_FAILURE);
}

void	exit_success(t_arg *arg)
{
	free_args(arg);
	exit(EXIT_SUCCESS);
}
