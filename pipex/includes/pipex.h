/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:38:04 by joonpark          #+#    #+#             */
/*   Updated: 2021/07/15 14:34:39 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>

/*
** ===========================
** MACROS
** ===========================
*/

# define WHICH_DIR "/usr/bin/which"

# define READ 0
# define WRITE 1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

/*
** ===========================
** struct typedef
** ===========================
*/

typedef struct s_fd
{
	int	fd;
	int	flag;
	int	mode;
}				t_fd;

typedef struct s_arg
{
	int		a[2];
	int		b[2];

	int		argc;
	char	**argv;
	char	**envp;
	char	**args;

	char	*infile;
	char	*outfile;

	int		fd;
	int		heredoc;
}				t_arg;

/*
** ========================
** basics
** ========================
*/
void	ft_run(t_arg *arg);
void	init(t_arg *arg, int argc, char *argv[], char *envs[]);
void	init_fd(t_fd *fd, int flag, int mode);
void	free_args(t_arg *arg);
void	exit_child(t_arg *arg, const char *msg);

/*
** ========================
** exec
** ========================
*/
void	exec(t_arg *arg, int idx);
void	find_executable(char *command, char *envs[],
			char buffer[], int buf_size);

/*
** ========================
** utils
** ========================
*/
char	**ft_split(char const *s, char c);
void	*ft_memset(void *b, int c, size_t len);
int		ft_strlen(const char *s);







#endif
