/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:38:04 by joonpark          #+#    #+#             */
/*   Updated: 2021/07/19 14:30:08 by joonpark         ###   ########.fr       */
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

# ifndef P_BUFFER_SIZE
#  define P_BUFFER_SIZE 4096
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
	char	*limeter;

	int		limeter_length;
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
void	handle_heredoc(t_arg *arg);

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
int		ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(char *str, char c);
char	*ft_strndup(const char *str, int n);
int		get_line(int fd, char **line);
void	*ft_memset(void *b, int c, size_t len);
#endif
