/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:17:47 by joonpark          #+#    #+#             */
/*   Updated: 2021/07/15 23:40:42 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	infile(t_arg *arg, int idx)
{
	t_fd	f;

	close(arg->a[READ]);
	init_fd(&f, O_RDONLY, 0);
	if (arg->heredoc)
	{
	}
	else
	{
		f.fd = open(arg->infile, f.flag | f.mode);
		if (f.fd < 0)
			exit_child(arg, "file open error.");
		dup2(f.fd, STDIN_FILENO);
		close(f.fd);
	}
	dup2(arg->a[WRITE], STDOUT_FILENO);
	exec(arg, idx + 1);
}

static void	outfile(t_arg *arg, int idx)
{
	t_fd	f;
	int		flag;

	flag = O_WRONLY | O_TRUNC | O_CREAT;
	if (arg->heredoc)
		flag = O_WRONLY | O_APPEND | O_CREAT;
	init_fd(&f, flag, S_IRUSR | S_IWUSR);
	f.fd = open(arg->outfile, f.flag, f.mode);
	if (idx % 2 == 0)
	{
		close(arg->b[WRITE]);
		dup2(arg->a[READ], STDIN_FILENO);
	}
	else
	{
		close(arg->a[WRITE]);
		dup2(arg->b[READ], STDIN_FILENO);
	}
	dup2(f.fd, STDOUT_FILENO);
	exec(arg, idx);
}

static void	child_process(t_arg *arg, int idx)
{
	if (idx == 1)
		infile(arg, idx);
	else if (idx == arg->argc - 2)
		outfile(arg, idx);
	else
	{
		if (idx % 2 == 0)
		{
			dup2(arg->a[READ], STDIN_FILENO);
			dup2(arg->b[WRITE], STDOUT_FILENO);
		}
		else
		{
			dup2(arg->b[READ], STDIN_FILENO);
			dup2(arg->a[WRITE], STDOUT_FILENO);
		}
		exec(arg, idx);
	}
	exit(EXIT_SUCCESS);
}

static void	parent_process(t_arg *arg, int pid, int idx)
{
	int	status;

	if (idx == 1)
		close(arg->a[WRITE]);
	else if (idx == arg->argc - 1 && idx % 2 == 0)
		close(arg->b[WRITE]);
	else if (idx == arg->argc - 1 && idx % 2 == 1)
		close(arg->a[WRITE]);
	else
	{
		if (idx % 2 == 0)
		{
			close(arg->b[WRITE]);
			close(arg->a[READ]);
		}
		else
		{
			close(arg->a[WRITE]);
			close(arg->b[READ]);
		}
	}
	waitpid(pid, &status, 0);
}

void	ft_run(t_arg *arg)
{
	int		idx;
	int		*p;
	pid_t	pid;

	idx = 0;
	while (++idx < arg->argc - 1)
	{
		p = arg->a;
		if (idx % 2 == 0)
			p = arg->b;
		pipe(p);
		pid = fork();
		if (pid == 0)
		{
			child_process(arg, idx);
		}
		else if (pid > 0)
		{
			parent_process(arg, pid, idx);
		}
	}
}
