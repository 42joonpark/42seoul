/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 11:07:04 by joonpark          #+#    #+#             */
/*   Updated: 2021/07/15 14:58:52 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_args(t_arg *arg)
{
	int	idx;

	if (arg->args)
	{
		idx = 0;
		while (arg->args[idx])
			free(arg->args[idx++]);
		if (arg->args)
		{
			free(arg->args);
			arg->args = NULL;
		}
	}
	return ;
}
