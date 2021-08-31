/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:27:26 by joonpark          #+#    #+#             */
/*   Updated: 2021/08/04 13:57:52 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	helper_func(t_arg *arg)
{
	int		fd;
	char	*line;

	fd = open(".temp", O_RDWR | O_CREAT | O_TRUNC, 0644);
	write(STDOUT_FILENO, "pipe heredoc> ", 14);
	while (get_line(STDIN_FILENO, &line) > 0)
	{
		if (ft_strncmp(arg->limeter, line, ft_strlen(line)) == 0)
			break ;
		write(STDOUT_FILENO, "pipe heredoc> ", 14);
		write(fd, line, ft_strlen(line));
		write(fd, &"\n", 1);
		free(line);
		line = NULL;
	}
	if (line)
		free(line);
	close(fd);
}

void	handle_heredoc(t_arg *arg)
{
	pid_t	pid;
	int		fd;

	pid = fork();
	if (pid == 0)
	{
		helper_func(arg);
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(NULL);
		fd = open(".temp", O_RDONLY);
		dup2(fd, STDIN_FILENO);
		close(fd);
		unlink(".temp");
	}
}
