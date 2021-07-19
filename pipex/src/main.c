/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:37:51 by joonpark          #+#    #+#             */
/*   Updated: 2021/07/19 09:20:37 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envs[])
{
	static const char	*msg = "usage: ./pipex file1 cmd1 cmd2 file2\n";
	t_arg				arg;

	if (argc < 5)
	{
		perror(msg);
		exit(EXIT_SUCCESS);
	}
	init(&arg, argc, argv, envs);
	ft_run(&arg);
}
