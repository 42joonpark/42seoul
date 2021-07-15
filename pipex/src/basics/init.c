/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:11:00 by joonpark          #+#    #+#             */
/*   Updated: 2021/07/15 14:35:51 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init(t_arg *arg, int argc, char *argv[], char *envs[])
{
	arg->argc = argc;
	arg->argv = argv;
	arg->envp = envs;
	arg->args = NULL;
	arg->infile = argv[1];
	arg->outfile = argv[argc - 1];
}

void	init_fd(t_fd *fd, int flag, int mode)
{
	fd->fd = -1;
	fd->flag = flag;
	fd->mode = mode;
}

