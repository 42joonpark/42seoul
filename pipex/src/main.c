/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:37:51 by joonpark          #+#    #+#             */
/*   Updated: 2021/07/14 15:40:12 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	infile(t_arg *arg, int idx)
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
		dup2(f.fd, STDIN_FILENO);
		close(f.fd);
	}
	dup2(arg->a[WRITE], STDOUT_FILENO);
	exec(arg, idx + 1);
}

void	outfile(t_arg *arg, int idx)
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

void	child_process(t_arg *arg, int idx)
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

void	parent_process(t_arg *arg, int pid, int idx)
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

int	main(int argc, char *argv[], char *envs[])
{
	static const char *msg = "usage: ./pipex file1 cmd1 cmd2 file2";
	t_arg	arg;


	if (argc < 5)
	{
		perror(msg);
		exit(1);
	}
	init(&arg, argc, argv, envs);
	ft_run(&arg);
}
