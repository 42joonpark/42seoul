/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:37:51 by joonpark          #+#    #+#             */
/*   Updated: 2021/07/19 09:21:05 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	move_argv(int *argc, char *argv[], t_arg *arg)
{
	int		idx;

	idx = 1;
	while (idx < *argc - 1)
	{
		argv[idx] = argv[idx + 1];
		++idx;
	}
	--(*argc);
	argv[*argc] = NULL;
	arg->heredoc = 1;
	arg->limeter = argv[1];
	arg->limeter_length = ft_strlen(argv[1]);
}

int	main(int argc, char *argv[], char *envs[])
{
	static const char	*msg = "usage: ./pipex [here_doc] cmd1 cmd2 file2\n";
	t_arg				arg;
	int					res;

	if (argc > 1)
	{
		res = ft_strncmp("here_doc", argv[1], ft_strlen("here_doc"));
		if (!res)
			move_argv(&argc, argv, &arg);
	}
	if (argc < 5)
	{
		perror(msg);
		exit(EXIT_SUCCESS);
	}
	init(&arg, argc, argv, envs);
	ft_run(&arg);
}
