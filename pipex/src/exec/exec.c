/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 11:46:10 by joonpark          #+#    #+#             */
/*   Updated: 2021/07/17 14:31:16 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(t_arg *arg, int idx)
{
	char	cmd[P_BUFFER_SIZE];

	arg->args = ft_split(arg->argv[idx], ' ');
	ft_memset(cmd, 0, P_BUFFER_SIZE);
	find_executable(arg->argv[idx], arg->envp, cmd, P_BUFFER_SIZE);
	cmd[ft_strlen(cmd) - 1] = '\0';

	if (access(cmd, F_OK) < 0)
		exit_child(arg, "command does not exist.");
	if (access(cmd, X_OK) < 0)
		exit_child(arg, "command not executable. check permission.");
	if (execve(cmd, arg->args, arg->envp) < 0)
		exit_child(arg, "execve() failed to execute command.");
}
