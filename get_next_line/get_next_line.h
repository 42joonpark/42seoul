/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonpark <joonpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:15:02 by joonpark          #+#    #+#             */
/*   Updated: 2021/05/20 19:40:51 by joonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1
# endif

int				get_next_line(int fd, char **line);
void			*ft_memset(void *b, int c, size_t len);
unsigned char	*ft_strchr(const unsigned char *str, int c);
unsigned char	*ft_strdup(const unsigned char *str);

#endif
